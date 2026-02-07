#!
#
# Create ui files for each language listed in FatMessages

my $inputfn = $ARGV[0]; 		# path to FatMessages
my $templatefn = $ARGV[1];	# path to UI Template
my $output = $ARGV[2];		# output path
my $stub = $ARGV[3];		# filename stub. like options.gtk3.ui will become enoptions.gtk3.ui

if (length($stub)<3) {
	print "invalid stub.\n";
	exit;
}

my $template;
my %langs = {'en'=>1};
my %trans;
$trans{'en'}{'foo'}='bar';

open(my $fh, '<', $templatefn) or die "cannot open template file $templatefn";
{
	local $/;
	$template = <$fh>;
}
close($fh);

$template =~ s/translatable="yes"/translatable="no"/g;

open(my $input, '<', $inputfn) or die "cannot open FatMessages file $inputfn";

while (<$input>)
{
	# skip comment and empty lines
	/^#/    && next;
	/^\s*$/ && next;

	# only parsing things that look like message lines:
	if( /^([a-z]{2}).([^.]+).([^:]+):(.*)/ )
	{
		my( $lang, $plat, $key, $val ) = ( $1, $2, $3, $4 );
		if ($plat == 'gtk')
		{
			$val =~ s|<.+?>||g; #remove HTML
			$langs{$lang}=1;
			$trans{$lang}{$key}=$val;
		}
	}

}

# load up langs hash with copy of the template for each lang

foreach $key (keys %langs)
{
	if (length($key)==2)
	{
		$langs{$key} = $template
	}
}

# iterate through each and key replace with translated text

foreach my $tran (keys %trans)
{
	foreach my $key (keys %{$trans{$tran}})
	{
		$langs{$tran} =~ s/\>$key\</\>$trans{$tran}{$key}\</g;
	}
}

# save the ui file for each language

foreach $key (keys %langs)
{
	if (length($key)==2)
	{
		open (OFN, '>', $output.'/'.$key.$stub) or die "cannot open output file ".$output.'/'.$key.$stub;
		print OFN $langs{$key};
		close (OFN);
	}
}

