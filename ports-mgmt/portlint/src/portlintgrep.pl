#!/usr/bin/perl
#
# Copyright (c) 2003 Oliver Eikemeier. All rights reserved.
#
# BSD licensed.
#

#
# List all the ports with FATAL errors:
#
# portlintgrep ^FATAL:
#

require 5.005;
use diagnostics;
use strict;
use Carp;

my $make     = $ENV{MAKE}     ? $ENV{MAKE}     : '/usr/bin/make';
my $portlint = $ENV{PORTLINT} ? $ENV{PORTLINT} : '/usr/local/bin/portlint';
my $portsdir = $ENV{PORTSDIR} ? $ENV{PORTSDIR} : '/usr/ports';
my $portlint_args = $ENV{PORTLINT_ARGS} ? $ENV{PORTLINT_ARGS} : '';

die "Usage: portlintgrep <regex>\n" if $#ARGV != 0;
my $regex = qr/$ARGV[0]/;

my %failedports;

my @categories = split ' ', `cd $portsdir; $make -VSUBDIR`;
foreach my $category (@categories) {
        my @ports = split ' ', `cd "$portsdir/$category"; $make -VSUBDIR`;
        foreach my $port (@ports) {
                my @result =
                    `cd "$portsdir/$category/$port"; $portlint $portlint_args`;
                map chomp, @result;
                my @filteredresult = grep /$regex/o, @result;
                if (@filteredresult) {
                        my $maintainer =
                            `cd "$portsdir/$category/$port"; $make -VMAINTAINER`;
                        chomp $maintainer;
                        push @{$failedports{$maintainer}}, "$category/$port";
                        print join("\n  ",
                                "$category/$port <$maintainer>:",
                                @filteredresult),
                            "\n";
                }
        }
}

print "\nPorts sorted by maintainer:\n";
foreach my $maintainer (sort { lc $a cmp lc $b } keys %failedports) {
        print join("\n - ", $maintainer, @{$failedports{$maintainer}}), "\n";
}
