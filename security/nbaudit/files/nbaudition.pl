#!/usr/bin/perl
use strict;

# $FreeBSD$

# run nmap -oX logfile <host> -p 139 to create the log for this script

# run audition.pl log.xml to begin the great enterprise.
# logging is done to /tmp/nbaud.log

# requires: nmap generated xml logs, nbaudit.

# author: lj
# contact: lj@bsd.sh

my ($date, $host, $status, $state);
my $in_block = 0;
chomp($date = `date`);
open(TMPLOG, ">>/tmp/nbaud.log") or die "cant write to logfile: $!";
print TMPLOG $date, " started\n";
close TMPLOG;
chomp(my $nbaudit = `which nbaudit`);
unless(-e $nbaudit){die "$!";}
while(<>)
{
chomp;
if (/<host>/){$in_block = 1;}
	if($in_block){

	WEE:{
	
	if(m/<status state=\"(.\S+)\"/)
	{

		if($1)
		{
			$status = $1; 
			if($status eq 'down')
			{
			next WEE;
			}
		}
	}
	
	if(m/<state state=\"(.\S+)\" \//)
	{
		if($1)
		{
			$state = $1;
			if($state ne 'open')
			{
			next WEE;
			}
		}
	}

	if (m/<address addr=\"(.\S+)\" /)
	{
		if($1)
		{
			$host = $1; 
		}
	}
	
	if(/<\/host>/){$in_block = 0;}
	if(($1) and ($host))
		{
			if(($1 eq $host) and ($status eq 'up') and ($state eq 'open'))
			{
#			print "\n$host is $status with port 139 $state\n";
			system("$nbaudit -o /tmp/nbaud.log $host");
			}
		}
		} #end of WEE
	} 

}
chomp($date = `date`);
open(TMPLOG, ">>/tmp/nbaud.log") or warn "$!";
print TMPLOG $date, " stopped\n";
close TMPLOG; 
print "\nfin.\n" and exit;
