package cmw;
##
## $Id: cmw.pm.in 3000 2015-01-06 18:47:49Z heas $
##
## rancid 3.1.99
## Copyright (c) 1997-2015 by Terrapin Communications, Inc.
## All rights reserved.
##
## This code is derived from software contributed to and maintained by
## Terrapin Communications, Inc. by Henry Kilmer, John Heasley, Andrew Partan,
## Pete Whiting, Austin Schutz, and Andrew Fort.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions
## are met:
## 1. Redistributions of source code must retain the above copyright
##    notice, this list of conditions and the following disclaimer.
## 2. Redistributions in binary form must reproduce the above copyright
##    notice, this list of conditions and the following disclaimer in the
##    documentation and/or other materials provided with the distribution.
## 3. All advertising materials mentioning features or use of this software
##    must display the following acknowledgement:
##        This product includes software developed by Terrapin Communications,
##        Inc. and its contributors for RANCID.
## 4. Neither the name of Terrapin Communications, Inc. nor the names of its
##    contributors may be used to endorse or promote products derived from
##    this software without specific prior written permission.
## 5. It is requested that non-binding fixes and modifications be contributed
##    back to Terrapin Communications, Inc.
##
## THIS SOFTWARE IS PROVIDED BY Terrapin Communications, INC. AND CONTRIBUTORS
## ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
## TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
## PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COMPANY OR CONTRIBUTORS
## BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
## CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
## SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
## INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
## CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
## POSSIBILITY OF SUCH DAMAGE.
#
#  RANCID - Really Awesome New Cisco confIg Differ
#
#  cmw.pm - Comware (Huawei/H3C/3com/HP) rancid procedures
#
# https://sites.google.com/site/jrbinks/code/rancid/cmwrancid

use 5.010;
use strict 'vars';
use warnings;
no warnings 'uninitialized';
require(Exporter);
our @ISA = qw(Exporter);

use rancid 3.1.99;

our $login;

@ISA = qw(Exporter rancid main);
#XXX @Exporter::EXPORT = qw($VERSION @commandtable %commands @commands);

# XXX
#our @EXPORT = qw(iproutesort iprouteval);

# load-time initialization
sub import {
    0;
}

# post-open(collection file) initialization
sub init {
    $login = "cmwlogin";
    # add content lines and separators
    ProcessHistory("","","","!RANCID-CONTENT-TYPE: $devtype\n!\n");

    0;
}

# main loop of input of device output
sub inloop {
    my($INPUT, $OUTPUT) = @_;
    my($cmd, $rval);

TOP: while(<$INPUT>) {
	tr/\015//d;
        if (/[\]>#]\a?\s*quit/) {
	#if (/[>#]\s?exit$/) {
	    $clean_run = 1;
	    last;
	}
	if (/^Error:/) {
	    print STDOUT ("$host $login error: $_");
	    print STDERR ("$host $login error: $_") if ($debug);
	    $clean_run = 0;
	    last;
	}
        while (/[\]>#]\a?\s*($cmds_regexp)\s*$/) {
	    $cmd = $1;

	    if (!defined($prompt)) {
		# Extract the prompt: look for something not [ or < at the start
		# of the line, until either ] or > or # is reached:
		$prompt = ($_ =~ /^([^\]>#]+[\]>]\a?)/)[0]; 
		$prompt =~ s/([][}{)(\\])/\\$1/g;
		print STDERR ("PROMPT MATCH: $prompt\n") if ($debug);
	    }
	    print STDERR ("HIT COMMAND:$_") if ($debug);
	    if (! defined($commands{$cmd})) {
		print STDERR "$host: found unexpected command - \"$cmd\"\n";
		$clean_run = 0;
		last TOP;
	    }
	    $rval = &{$commands{$cmd}}($INPUT, $OUTPUT, $cmd);
	    delete($commands{$cmd});
	    if ($rval == -1) {
		$clean_run = 0;
		last TOP;
	    }
	}
    }
}

# dummy function
sub DoNothing {print STDOUT;}

# This is a sort routine that will sort on the
# ip route when the ip route is anywhere in
# the strings.
sub iproutesort {
    my(%lines) = @_;
    my($i) = 0;
    my(@sorted_lines);
    foreach my $iproute (sort sortbyiproute keys %lines) {
	$sorted_lines[$i] = $lines{$iproute};
	$i++;
    }
    @sorted_lines;
}

## XXX Re-evaluate based on new routines, and consider IPv6:
# These two routines will sort based upon IP route
sub iprouteval {
    my(@a) = ($_[0] =~ m#^(\d+)\.(\d+)\.(\d+)\.(\d+)/(\d+)$#);
    $a[4] + ($a[3] + 256 * ($a[2] + 256 * ($a[1] + 256 * $a[0])));
}

sub sortbyiproute {
    &iprouteval($a) <=> &iprouteval($b);
}

# Clean up lines on input, particularly ANSI characters as a result
# of us not being able to turn off per-session terminal paging
sub filter_lines {
    my ($l) = (@_);

    #s/^\033\[42D +\033\[42D(.+)$/$1/;
    #s/\033\133\064\062\104\s*\033\133\064\062\104//g;
    $l =~ s/\033\133\064\062\104\s+\033\133\064\062\104//g;
    $l =~ s/\033\133\061\066\104\s+\033\133\061\066\104//g;
    $l =~ s/\033\133\064\062\104//g;
    $l =~ s/\033\133\061\062\104//g;
    $l =~ s/.*\[37D(.*)/$1/g;    # MA5600
    # Probably not needed:
    $l =~ s/\s*---- More ----\s*//;
    $l =~ s/^               //; # Comware7
    $l =~ s/Synchronization is finished.//g;
    return $l;
}

# Some commands are not supported on some models or versions
# of code.
# Remove the associated error messages, and rancid will ensure that
# these are not treated as "missed" commands
sub command_not_valid {
    my ($l) = (@_);

    if ( $l =~
	/% Too many parameters found at '\^' position/ ||
	/% Unrecognized command found at '\^' position/ ||
	/% Incomplete command found at '\^' position./ ||
	/(% )?Wrong parameter found at '\^' position/ ||
	/% Wrong device .+/
    ) {
	return(1);
    } else {
	return(0);
    }
}

# Some commands are not authorized under the current
# user's permissions
sub command_not_auth {
    my ($l) = (@_);

    if ( $l =~
	/Permission denied\./
    ) {
	return(1);
    } else {
	return(0);
    }
}

# Some output lines are always skipped
sub skip_pattern {
    my ($l) = (@_);

    if ( $l =~
	/^\s+\^$/ ||
        /^$/
    ) {
	return(1);
    } else {
	return(0);
    }
}

sub DisplayFib {

    my($INPUT, $OUTPUT, $cmd) = @_;
    my($dest, $nexthop, $flag, $outint, $label);
    print STDERR "    In DisplayFib: $_" if ($debug);

    chomp;

    # Display the command we're processing in the output:
    ProcessHistory("FIB","","","!\n! '$cmd':\n!\n");

    while (<$INPUT>) {
        tr/\015//d;
        last if(/^\s*$prompt/);
        chomp;
        $_ = filter_lines($_);

	return(1) if command_not_valid($_);
	return(-1) if command_not_auth($_);
	next if skip_pattern($_);

        next if /^Destination count: \d+ FIB entry count: \d+/;

        # Chop out some detail that changes over time (Comware 3):
        s/(\s+)TimeStamp\s+/$1/;        # TimeStamp column heading

        ProcessHistory("FIB","","","! $_\n");

        if ( m,Destination/Mask, ) {
            while (<$INPUT>) {
                tr/\015//d;
                last if(/^\s*$prompt/);
                chomp;
                $_ = filter_lines($_);

                # Chop out some detail that changes over time (Comware 3):
                s/(\s+)t\[\d+\]\s+/$1/;    # TimeStamp data

                # "display fib" on comware7 shows host entries for things
                # learned via arp too.  For a distribution router, that's all
                # the devices on subnets routed by it!
                # If we filter out all "UH" entries that are NOT InLoop, we
                # get acceptable output.
                #
                # So we want to keep:
                #
                # 0.0.0.0/32         127.0.0.1       UH  InLoop0 Null
                #
                # but reject:
                #
                # 130.159.44.161/32  130.159.44.161  UH  Vlan44  Null
                #
                # However I've a feeling that this is a problematic
                # solution, and some object to the notion that rancid
                # should be representing such potentially dynamic data in
                # the first place, which is why we created the
                # $display_fib flag for rancid 2, and in rancid 3 one
		# can modify the command table in rancid.types.conf

		($dest, $nexthop, $flag, $outint, $label) = split;
                next if ( $flag eq 'UH' && $outint !~ /InLoop/ );
                #ProcessHistory("FIB", "cmw::iproutesort", "$dest", "! $_\n");
                ProcessHistory("FIB", "ipsort", "$dest", "! $_\n");
            }

            ProcessHistory("FIB", "", "", "!\n");

            # return here to ensure that we don't keep swallowing the
            # next command's output by returning to the surrounding
            # while loop
            return(0);
        }
    }
    return(0);
}

sub DisplayIPRoutes {
    my($INPUT, $OUTPUT, $cmd) = @_;
    my($key,$line,$spaces);
    print STDERR "    In DisplayIPRoutes: $_" if ($debug);

    chomp;

    # Display the command we're processing in the output:
    ProcessHistory("IPR","","","!\n! '$cmd':\n!\n");

    while (<$INPUT>) {
        tr/\015//d;
        last if(/^\s*$prompt/);
        chomp;

        $_ = filter_lines($_);
	return(1) if command_not_valid($_);
	return(-1) if command_not_auth($_);
	next if skip_pattern($_);

        ProcessHistory("IPR","","","! $_\n");

        if ( m,Destination/Mask, ) {
            my $lastkey = "";
            my $lastspaces = "";
            while (<$INPUT>) {
                tr/\015//d;
                last if(/^\s*$prompt/);
                chomp;
                $_ = filter_lines($_);

                # If the key is blank, indicating multiple nexthops for
                # a particular route, then we use the previous one
                if ( m/^\s+(.+)/ ) {
                    $key = $lastkey;
                    $line = $key . $lastspaces . $1;
                    #ProcessHistory("IPR", "cmw::iproutesort", "$key", "! $line\n");
                    ProcessHistory("IPR", "ipsort", "$key", "! $line\n");
                }
                if ( m/^(\S+)(\s+).+/ ) {
                    $key = $1;
                    $line = $_;
                    $spaces = $2;
                    #ProcessHistory("IPR", "cmw::iproutesort", "$key", "! $line\n");
                    ProcessHistory("IPR", "ipsort", "$key", "! $line\n");

		    # Remember these, we may need them on the next pass
                    $lastkey = $key;
                    $lastspaces = $spaces;
                }
            }

            ProcessHistory("IPR", "", "", "!\n");

            # return here to ensure that we don't keep swallowing the
            # next command's output by returning to the surrounding
            # while loop
            return(0);
        }
    }
    return(0);
}

## This routine processes general output of "display" commands
sub CommentOutput {
    my($INPUT, $OUTPUT, $cmd) = @_;
    print STDERR "    In CommentOutput: $_" if ($debug);

    chomp;

    # Display the command we're processing in the output:
    ProcessHistory("COMMENTS", "", "", "!\n! '$cmd':\n!\n");

    while (<$INPUT>) {
        tr/\015//d;

        # If we find the prompt, we're done
        # Ordinarily this matches from the start of the line, however
        # we've seen circumstances at least in Comware7 where the
        # prompt is preceded by whitespace, like so:
        # ^M^M               ^M<router>display boot-loader^M
        last if(/^\s*$prompt/);
        chomp;

	# filter out some junk
        $_ = filter_lines($_);
	return(1) if command_not_valid($_);
	return(-1) if command_not_auth($_);
	next if skip_pattern($_);

	# Now we skip or modify some lines from various commands to
        # remove irrelevant content, or to avoid insignificant diffs

        # 'display local-user':
        s/\s+Current AccessNum:.+$//;

        # 'display version':
        next if (/^(Uptime is \d|.+ [Uu]ptime is \d).+$/);
        # No longer necessary since skipping the whole Uptime line:
        # Mangle these lines:
        #s/(.*)[Uu]ptime.*.weeks.*.days*.*hours*.*minutes*(.*)/$1 $2/;
        #s/(.*)[Uu]ptime.*days*.*hours*.*minutes*(.*)/$1 $2/;

        # MSRs display a 'last reboot' time, but sometimes the seconds
        # vary by one or two (presumably internal rounding), so simply make
        # the last digit a fixed '0'.  It would probably be safer to make
        # the last two digits a fixed '00'.
        # (Thx Alexander Belokopytov)
        s/(^Last reboot.+)\d$/${1}0/;

        # 'dir ' commands
        if ( $cmd =~ /^dir / ) {
            # First field is just an index number, chop it out
            s/^\s+\d+\s+(.+)/ $1/;
            # Remove filenames that are updated frequently
            next if (
                /logfile\.log$/ ||
                /lauth\.dat$/ ||
                /ifindex\.dat$/ ||
                /startup\.mdb$/ ||
                /private-data\.txt$/ ||
                /.+ KB total \(.+ KB free/ ||
                /.+ KB total \(.+ KB free/ ||
                /\.trash/
            );
        }

	# 'display ospf brief'/'display ospf'
        if ( $cmd =~ 'display ospf( brief)?' ) {
            #next if (/^(Ospf is not enabled yet|Info: OSPF routing process is not enabled|The feature OSPF has not been enabled.).+$/);
            next if (/^\s+SPF (Computation|Scheduled|calculation) Count:.+$/i);
        }

        if ( $cmd eq 'display power' ) {
            next if (/^(\s+Input Power).+$/);
        }

        if ( $cmd eq 'display poe powersupply' ) {
            next if (/^(PSE Total Power Consumption|PSE Available Power|PSE Peak Value|PSE Average Value).+$/);
        }

        if ( $cmd eq 'display ntp-service status' ) {
            next unless m/(Clock status|Clock stratum|Reference clock ID)/i;
        }

        if ( $cmd eq 'display transceiver interface' ) {
            s/^(\S+ transceiver information:).+$/$1/;   # filter random garbage
            s/^Error: The transceiver is absent.$/  No transceiver present./;
            s/^Error: The combo port is inactive.$/  Inactive combo port./;
        }

        # Add the processed lines to the output buffer:
        ProcessHistory("COMMENTS","","","! $_\n");
    }

    # Add a blank comment line to the output buffer
    ProcessHistory("COMMENTS", "", "", "!\n");
    return(0);
}

## This routine processes a "display current"
sub DisplayCurrent {
    my($INPUT, $OUTPUT, $cmd) = @_;
    print STDERR "    In DisplayCurrent: $_" if ($debug);


    while (<$INPUT>) {
        tr/\015//d;
        last if(/^\s*$prompt/);
        chomp;

        $_ = filter_lines($_);
	return(1) if command_not_valid($_);
	return(-1) if command_not_auth($_);
	next if skip_pattern($_);

        return(0) if ($found_end);

        # Filter out some sensitive data:
        if ( $filter_commstr &&
             /^ ?(snmp-agent (target-host.+securityname|usm-user|community (read|write)) )(\S+)/
           ) {
            ProcessHistory("","","","! $1<removed>$'\n");
            next;
        }
        if ( $filter_pwds >= 1 &&
            /^ ?(password (?:simple|cipher|hash) )(\S+)/ ||
            /^ ?(super password( role level-\d)( level \d)? (cipher|simple|hash) )(\S+)/ ||
            /^ ?(set authentication password (cipher|simple|hash) )(\S+)/ ||
            /^ ?(key (?:authentication|accounting) )(\S+)/ 
           ) {
            ProcessHistory("","","","! $1<removed>$'\n");
            next;
        }

        # filter ssh public keys of devices connected to from this device
        if (/^ ?(public-key-code begin)/ &&
                $filter_pwds >= 2) {
            ProcessHistory("","","","!$1\n");
            ProcessHistory("","","","! <removed>\n");
            while (<$INPUT>) {
                tr/\015//d;
                next if /^$/;
		next if /^\s+[[:xdigit:]]$/;
                if (/(^ public-key-code end)/) {
                    ProcessHistory("","","","!$1\n");
                    last;
                }
            }
        next;
        }

	# Filter mac addresses dynamically added to config
	next if (/^ ?mac-address security.+$/);

        ProcessHistory("", "", "", "$_\n");

        # end of config
        if (/^return/) {
            $found_end = 1;
            return(0);
        }
    }
    return(0);
}

1;

__END__


