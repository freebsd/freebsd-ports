#!/usr/bin/perl

# sq(eeze) / unsq(eeze) - pre-compressor for sorted word lists
# Copyright (C) 2000 Björn Jacke <bjoern.jacke@gmx.de>
#
# This program comes with ABSOLUTELY NO WARRANTY; it may be copied or modified
# under the terms of the GNU General Public License version 2 as published
# by the Free Software Foundation.

# This is a `multi-call-program'. If it's called as `unsq' or `unsq.pl'
# it decompresses -- otherwise it is in compress mode. Input and Output only
# via STDIN and STDOUT. It does almost the same job as the sq/unsq from
# Ispell -- just better ;-)
#
# PS: For best compression results use POSIX sorting order in spite of any
#     other locale-depending sorting order (set LC_ALL and LC_COLLATE to POSIX)

# version 1.2


@size_arr =  qw(0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J
		K L M N O P Q R S T U V W X Y Z a b c d
		e f g h i j k l m n o p q r s t u v w x y z);
$MAX_PREFIX = $#size_arr;


sub trunc {

	if ($word eq $prev) {
		$same = length($word);
	}
	else {
		$same = 0;
		while (substr($word,$same,1) eq substr($prev,$same,1)) {
			$same++;
		}
	}

	if ($same > $MAX_PREFIX) {
		$same = $MAX_PREFIX;
	}

	print STDOUT $size_arr[$same], substr($word,$same);

	$prev = $word;
}


sub expand {

	  # keep relevant part of previous word:
	$prev = substr($prev, 0, $to_num{substr($word,0,1)} );
	  # strip first (meta)-character from word:
	$word = substr($word,1);
	  # concatenate new word and name it prev ...
	$prev = "$prev$word";
	print STDOUT $prev;
}



######  main ######

$0 =~ s/.*?unsq(\.pl)?$/unsq/i;

$prev = "";


if ($0 eq "unsq") {
    
	$i = 0;
	foreach (@size_arr) {
		$to_num{$_} = $i++;
	}
	$do_it = \&expand;
}

else {
	$do_it = \&trunc;
}


while ($word = <STDIN>) {
	&$do_it;
}
