# New ports collection makefile for:	www/p5-MojoMojo
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MojoMojo
PORTVERSION=	1.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Catalyst & DBIx::Class powered Wiki

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Please keep order as in Makefile.PL
RUN_DEPENDS=	\
	p5-Plack>=0.9974:${PORTSDIR}/www/p5-Plack \
	p5-Algorithm-Diff>=1.1901:${PORTSDIR}/devel/p5-Algorithm-Diff \
	p5-Algorithm-Merge>=0:${PORTSDIR}/devel/p5-Algorithm-Merge \
	p5-Archive-Zip>=1.14:${PORTSDIR}/archivers/p5-Archive-Zip \
	p5-Cache-FastMmap>=1.31:${PORTSDIR}/devel/p5-Cache-FastMmap \
	p5-Catalyst-Runtime>=5.71001:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-Catalyst-Action-RenderView>=0.07:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
	p5-Catalyst-Authentication-Store-DBIx-Class>=0.101:${PORTSDIR}/www/p5-Catalyst-Authentication-Store-DBIx-Class \
	p5-Catalyst-Controller-HTML-FormFu>=0.03007:${PORTSDIR}/www/p5-Catalyst-Controller-HTML-FormFu \
	p5-Catalyst-Engine-PSGI>=0:${PORTSDIR}/www/p5-Catalyst-Engine-PSGI \
	p5-Catalyst-Model-DBIC-Schema>=0.01:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
	p5-Catalyst-Plugin-Authentication>=0.10005:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
	p5-Catalyst-Plugin-Cache>=0.08:${PORTSDIR}/www/p5-Catalyst-Plugin-Cache \
	p5-Catalyst-Plugin-ConfigLoader>=0.13:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
	p5-Catalyst-Plugin-I18N>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-I18N \
	p5-Catalyst-Plugin-SubRequest>=0.13:${PORTSDIR}/www/p5-Catalyst-Plugin-SubRequest \
	p5-Catalyst-Plugin-Session-State-Cookie>=0.11:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
	p5-Catalyst-Plugin-Session-Store-Cache>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-Cache \
	p5-Catalyst-Plugin-Setenv>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Setenv \
	p5-Catalyst-Plugin-Static-Simple>=0.07:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
	p5-Catalyst-Plugin-Unicode>=0.8:${PORTSDIR}/www/p5-Catalyst-Plugin-Unicode \
	p5-Catalyst-View-TT>=0.23:${PORTSDIR}/www/p5-Catalyst-View-TT \
	p5-Catalyst-View-JSON>=0.26:${PORTSDIR}/www/p5-Catalyst-View-JSON \
	p5-Catalyst-View-Email>=0:${PORTSDIR}/www/p5-Catalyst-View-Email \
	p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
	p5-Config-JFDI>=0:${PORTSDIR}/devel/p5-Config-JFDI \
	p5-Crypt-CBC>=2.12:${PORTSDIR}/security/p5-Crypt-CBC \
	p5-Data-Page>=2.00:${PORTSDIR}/databases/p5-Data-Page \
	p5-DateTime>=0.28:${PORTSDIR}/devel/p5-DateTime \
	p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
	p5-DBD-SQLite>=1.08:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBIx-Class>=0.08:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-DBIx-Class-DateTime-Epoch>=0.04:${PORTSDIR}/databases/p5-DBIx-Class-DateTime-Epoch \
	p5-DBIx-Class-EncodedColumn>=0:${PORTSDIR}/databases/p5-DBIx-Class-EncodedColumn \
	p5-DBIx-Class-TimeStamp>=0.11:${PORTSDIR}/databases/p5-DBIx-Class-TimeStamp \
	p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
	p5-File-MMagic>=1.27:${PORTSDIR}/devel/p5-File-MMagic \
	p5-File-Slurp>=9999.13:${PORTSDIR}/devel/p5-File-Slurp \
	p5-HTML-Parser>=3.60:${PORTSDIR}/www/p5-HTML-Parser \
	p5-HTML-FormFu>=0.02000:${PORTSDIR}/www/p5-HTML-FormFu \
	p5-HTML-FormFu-Model-DBIC>=0:${PORTSDIR}/www/p5-HTML-FormFu-Model-DBIC \
	p5-HTML-Strip>=1.04:${PORTSDIR}/www/p5-HTML-Strip \
	p5-HTML-TagCloud>=0:${PORTSDIR}/www/p5-HTML-TagCloud \
	p5-HTML-Toc>=0:${PORTSDIR}/www/p5-HTML-Toc \
	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
	p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager \
	p5-Image-Math-Constrain>=0:${PORTSDIR}/graphics/p5-Image-Math-Constrain \
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-KinoSearch>=0.165:${PORTSDIR}/textproc/p5-KinoSearch \
	p5-Module-Pluggable-Ordered>=1.4:${PORTSDIR}/devel/p5-Module-Pluggable-Ordered \
	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
	p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat \
	p5-Number-Format>=0:${PORTSDIR}/textproc/p5-Number-Format \
	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-Template-Plugin-JavaScript>=0:${PORTSDIR}/www/p5-Template-Plugin-JavaScript \
	p5-Text-Context>=3.5:${PORTSDIR}/textproc/p5-Text-Context \
	p5-Text-MultiMarkdown>=1.000031:${PORTSDIR}/textproc/p5-Text-MultiMarkdown \
	p5-Text-Password-Pronounceable>=0:${PORTSDIR}/security/p5-Text-Password-Pronounceable \
	p5-Text-Textile>=0:${PORTSDIR}/textproc/p5-Text-Textile \
	p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
	p5-YAML>=0.36:${PORTSDIR}/textproc/p5-YAML \
	p5-Term-Prompt>=0:${PORTSDIR}/devel/p5-Term-Prompt
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	mojomojo_cgi.pl.1 \
	mojomojo_create.pl.1 \
	mojomojo_fastcgi.pl.1 \
	mojomojo_fastcgi_manage.pl.1 \
	mojomojo_server.pl.1 \
	mojomojo_spawn_db.pl.1 \
	mojomojo_test.pl.1 \
	mojomojo_update_db.pl.1
MAN3=	MojoMojo.3 \
	MojoMojo::Controller::Admin.3 \
	MojoMojo::Controller::Attachment.3 \
	MojoMojo::Controller::Comment.3 \
	MojoMojo::Controller::Export.3 \
	MojoMojo::Controller::Gallery.3 \
	MojoMojo::Controller::Image.3 \
	MojoMojo::Controller::JSON.3 \
	MojoMojo::Controller::Journal.3 \
	MojoMojo::Controller::Jsrpc.3 \
	MojoMojo::Controller::Page.3 \
	MojoMojo::Controller::PageAdmin.3 \
	MojoMojo::Controller::Root.3 \
	MojoMojo::Controller::Tag.3 \
	MojoMojo::Controller::User.3 \
	MojoMojo::Declaw.3 \
	MojoMojo::Extension.3 \
	MojoMojo::Extensions::Counter.3 \
	MojoMojo::Formatter.3 \
	MojoMojo::Formatter::Amazon.3 \
	MojoMojo::Formatter::CPANHyperlink.3 \
	MojoMojo::Formatter::Comment.3 \
	MojoMojo::Formatter::Defang.3 \
	MojoMojo::Formatter::Dir.3 \
	MojoMojo::Formatter::DocBook.3 \
	MojoMojo::Formatter::DocBook::Colorize.3 \
	MojoMojo::Formatter::Emote.3 \
	MojoMojo::Formatter::File.3 \
	MojoMojo::Formatter::File::DocBook.3 \
	MojoMojo::Formatter::File::Image.3 \
	MojoMojo::Formatter::File::Pod.3 \
	MojoMojo::Formatter::File::Text.3 \
	MojoMojo::Formatter::Gist.3 \
	MojoMojo::Formatter::GoogleSearch.3 \
	MojoMojo::Formatter::GoogleCalendar.3 \
	MojoMojo::Formatter::IDLink.3 \
	MojoMojo::Formatter::IRCLog.3 \
	MojoMojo::Formatter::Include.3 \
	MojoMojo::Formatter::Main.3 \
	MojoMojo::Formatter::Markdown.3 \
	MojoMojo::Formatter::Pod.3 \
	MojoMojo::Formatter::RSS.3 \
	MojoMojo::Formatter::Redirect.3 \
	MojoMojo::Formatter::SyntaxHighlight.3 \
	MojoMojo::Formatter::TOC.3 \
	MojoMojo::Formatter::Text.3 \
	MojoMojo::Formatter::Textile.3 \
	MojoMojo::Formatter::Wiki.3 \
	MojoMojo::Formatter::WikipediaLink.3 \
	MojoMojo::Formatter::YouTube.3 \
	MojoMojo::I18N.3 \
	MojoMojo::Installation.3 \
	MojoMojo::Model::DBIC.3 \
	MojoMojo::Model::Search.3 \
	MojoMojo::Model::Themes.3 \
	MojoMojo::Prefs.3 \
	MojoMojo::Schema.3 \
	MojoMojo::Schema::Base::Result.3 \
	MojoMojo::Schema::Base::ResultSet.3 \
	MojoMojo::Schema::Result::Attachment.3 \
	MojoMojo::Schema::Result::Comment.3 \
	MojoMojo::Schema::Result::Content.3 \
	MojoMojo::Schema::Result::Entry.3 \
	MojoMojo::Schema::Result::Journal.3 \
	MojoMojo::Schema::Result::Link.3 \
	MojoMojo::Schema::Result::Page.3 \
	MojoMojo::Schema::Result::PageVersion.3 \
	MojoMojo::Schema::Result::PathPermissions.3 \
	MojoMojo::Schema::Result::Person.3 \
	MojoMojo::Schema::Result::Photo.3 \
	MojoMojo::Schema::Result::Preference.3 \
	MojoMojo::Schema::Result::Role.3 \
	MojoMojo::Schema::Result::RoleMember.3 \
	MojoMojo::Schema::Result::RolePrivilege.3 \
	MojoMojo::Schema::Result::Tag.3 \
	MojoMojo::Schema::Result::WantedPage.3 \
	MojoMojo::Schema::ResultSet::Attachment.3 \
	MojoMojo::Schema::ResultSet::Content.3 \
	MojoMojo::Schema::ResultSet::Page.3 \
	MojoMojo::Schema::ResultSet::Person.3 \
	MojoMojo::Schema::ResultSet::Role.3 \
	MojoMojo::Schema::ResultSet::Tag.3 \
	MojoMojo::View::Email.3 \
	MojoMojo::View::JSON.3 \
	MojoMojo::View::TT.3 \
	MojoMojo::WordDiff.3 \
	Text::SmartyPants.3 \
	Text::Wikispaces2Markdown.3

OPTIONS=	DEPLOY		"Automatic database deployment" Off \
		FASTCGI		"FastCGI support"		Off \
		TOCGEN		"Table of Contents generator"	Off \
		RECAPTCHA	"reCAPTCHA for anonymous edits"	Off \
		SYNTAX_HIGHLIGHT "Syntax highlighter"		Off \
		RSS_FORMATTER	"RSS formatter"			Off \
		DOCBOOK_FORMATTER "DocBook formatter"		Off \
		POD_FORMATTER	"POD formatter"			Off \
		TRANSCLUSION	"Transclusion support"		Off \
		AMAZON		"Amazon boxes"			Off \
		EMOTICONS	"Emoticons"			Off

.include <bsd.port.options.mk>

.if defined(WITH_DEPLOY)
RUN_DEPENDS+=	p5-SQL-Translator>=0.09006:${PORTSDIR}/databases/p5-SQL-Translator
.endif

.if defined(WITH_FASTCGI)
RUN_DEPENDS+=	p5-FCGI-ProcManager>=0:${PORTSDIR}/www/p5-FCGI-ProcManager
.endif

.if defined(WITH_TOCGEN)
RUN_DEPENDS+=	p5-HTML-Toc>=1.10:${PORTSDIR}/www/p5-HTML-Toc
.endif

.if defined(WITH_RECAPTCHA)
RUN_DEPENDS+=	p5-HTML-FormFu>=0:${PORTSDIR}/www/p5-HTML-FormFu
.endif

.if defined(WITH_SYNTAX_HIGHLIGHT)
RUN_DEPENDS+=	p5-Syntax-Highlight-Engine-Kate>=0:${PORTSDIR}/textproc/p5-Syntax-Highlight-Engine-Kate
.endif

.if defined(WITH_RSS_FORMATTER)
RUN_DEPENDS+=	p5-XML-Feed>=0:${PORTSDIR}/textproc/p5-XML-Feed
.endif

.if defined(WITH_DOCBOOK_FORMATTER)
RUN_DEPENDS+=	p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=1.66:${PORTSDIR}/textproc/p5-XML-LibXSLT
.endif

.if defined(WITH_POD_FORMATTER)
RUN_DEPENDS+=	p5-Pod-Simple>=3.01:${PORTSDIR}/textproc/p5-Pod-Simple
.endif

.if defined(WITH_TRANSCLUSION)
RUN_DEPENDS+=	p5-URI-Fetch>=0:${PORTSDIR}/www/p5-URI-Fetch \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
.endif

.if defined(WITH_AMAZON)
RUN_DEPENDS+=	p5-Net-Amazon>=0:${PORTSDIR}/net/p5-Net-Amazon
.endif

.if defined(WITH_EMOTICONS)
RUN_DEPENDS+=	p5-Text-Emoticon-MSN>=0:${PORTSDIR}/textproc/p5-Text-Emoticon-MSN
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-Encode>=2.31:${PORTSDIR}/converters/p5-Encode \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
