use ExtUtils::MakeMaker;

WriteMakefile(
	NAME		=> 'HTML::Embperl',
	VERSION_FROM	=> 'Embperl.pm',
	OBJECT		=> 'Embperl$(OBJ_EXT) epmain$(OBJ_EXT) epio$(OBJ_EXT) '.
			'epchar$(OBJ_EXT) epcmd$(OBJ_EXT) eputil$(OBJ_EXT) '.
			'epeval$(OBJ_EXT) epapinit$(OBJ_EXT)',
	MAN3PODS	=> {
		'Embperl.pod'		=> '$(INST_MAN3DIR)/HTML::Embperl.3',
		'EmbperlD.pod'		=> '$(INST_MAN3DIR)/HTML::EmbperlD.3',
		'EmbperlObject.pm'	=> '$(INST_MAN3DIR)/HTML::EmbperlObject.3',
	},
	PM		=> {
		'Embperl.pm'		=> '$(INST_LIBDIR)/Embperl.pm',
		'EmbperlObject.pm'	=> '$(INST_LIBDIR)/EmbperlObject.pm',
		'Embperl/Module.pm'	=> '$(INST_LIBDIR)/Embperl/Module.pm',
		'Embperl/Mail.pm'	=> '$(INST_LIBDIR)/Embperl/Mail.pm',
		'Embperl/Session.pm'	=> '$(INST_LIBDIR)/Embperl/Session.pm',
		'Embperl.pod'		=> '$(INST_LIBDIR)/Embperl.pod',
		'EmbperlD.pod'		=> '$(INST_LIBDIR)/EmbperlD.pod',
		'Intro.pod'		=> '$(INST_LIBDIR)/Embperl/Intro.pod',
		'IntroD.pod'		=> '$(INST_LIBDIR)/Embperl/IntroD.pod',
		'IntroEmbperlObject.pod'=> '$(INST_LIBDIR)/IntroEmbperlObject.pod',
		'Features.pod'		=> '$(INST_LIBDIR)/Embperl/Features.pod',
		'FeaturesD.pod'		=> '$(INST_LIBDIR)/Embperl/FeaturesD.pod',
		'Faq.pod'		=> '$(INST_LIBDIR)/Embperl/Faq.pod',
		'TipsAndTricks.pod'	=> '$(INST_LIBDIR)/Embperl/TipsAndTricks.pod',
		'embpcgi.pl'		=> '$(INST_LIBDIR)/Embperl/embpcgi.pl',
		'epocgi.pl'		=> '$(INST_LIBDIR)/Embperl/epocgi.pl',
	},
	EXE_FILES	=> [ 'embpexec.pl' ],
	PREREQ_PM	=> "@ARGV" !~ /\bDEFINE=-DAPACHE\b/ ? {} :
	{
		'Apache::Session'	=> '1.50',
		'mod_perl'		=> '1.22',
	},
	ABSTRACT	=> 'Embed Perl code in HTML documents',
	AUTHOR		=> 'Gerald Richter <richter@dev.ecos.de>',
);

@bins = ('embpexec.pl', 'embpcgi.pl', 'epocgi.pl');
foreach (@bins) {
	rename "$_.templ", $_;
}
