#!/usr/local/bin/perl

# usage: ./script.pl /usr/bin/youtube-viewer > new-youtube-viewer

my $sub = '';
while(<>){
    s{^use 5.01\K\d}{0};
    $sub = $1 if /^sub\s+(\w+)/;
    s{^\s+(?:or)?\s*\K__SUB__->\(}{$sub(};
    s{\b__SUB__\b}{\\&$sub};
    print;
}
