# New ports collection makefile for:	www/p5-MojoMojo
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MojoMojo
PORTVERSION=	0.999027
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Catalyst & DBIx::Class powered Wiki

RUN_DEPENDS=	\
	p5-Algorithm-Diff>=1.1901:${PORTSDIR}/devel/p5-Algorithm-Diff \
	p5-Algorithm-Merge>=0:${PORTSDIR}/devel/p5-Algorithm-Merge \
	p5-Archive-Zip>=1.14:${PORTSDIR}/archivers/p5-Archive-Zip \
	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-Catalyst-Action-RenderView>=0.07:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
	p5-Catalyst-Controller-HTML-FormFu>=0.02000:${PORTSDIR}/www/p5-Catalyst-Controller-HTML-FormFu \
	p5-Catalyst-Model-DBIC-Schema>=0.01:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
	p5-KinoSearch>=0:${PORTSDIR}/textproc/p5-KinoSearch \
	p5-Catalyst-Plugin-Authentication>=0.10005:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
	p5-Catalyst-Authentication-Store-DBIx-Class>=0.101:${PORTSDIR}/www/p5-Catalyst-Authentication-Store-DBIx-Class \
	p5-Catalyst-Plugin-Email>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Email \
	p5-Catalyst-Plugin-ConfigLoader>=0.13:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
	p5-Catalyst-Plugin-Session-Store-File>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-File \
	p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
	p5-Catalyst-Plugin-Singleton>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-Singleton \
	p5-Catalyst-Plugin-Static-Simple>=0.07:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
	p5-Catalyst-Plugin-SubRequest>=0.09:${PORTSDIR}/www/p5-Catalyst-Plugin-SubRequest \
	p5-Catalyst-Plugin-Unicode>=0.8:${PORTSDIR}/www/p5-Catalyst-Plugin-Unicode \
	p5-Catalyst-Plugin-I18N>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-I18N \
	p5-Catalyst-View-TT>=0.23:${PORTSDIR}/www/p5-Catalyst-View-TT \
	p5-Catalyst-View-JSON>=0:${PORTSDIR}/www/p5-Catalyst-View-JSON \
	p5-Cache>=0:${PORTSDIR}/devel/p5-Cache \
	p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
	p5-Data-FormValidator-Constraints-DateTime>=0:${PORTSDIR}/textproc/p5-Data-FormValidator-Constraints-DateTime \
	p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
	p5-DBIx-Class-DateTime-Epoch>=0:${PORTSDIR}/databases/p5-DBIx-Class-DateTime-Epoch \
	p5-DBIx-Class-HTML-FormFu>=0:${PORTSDIR}/databases/p5-DBIx-Class-HTML-FormFu \
	p5-HTML-FormFu-Model-DBIC>=0:${PORTSDIR}/www/p5-HTML-FormFu-Model-DBIC \
	p5-DBIx-Class-EncodedColumn>=0:${PORTSDIR}/databases/p5-DBIx-Class-EncodedColumn \
	p5-Module-Pluggable-Ordered>=1.4:${PORTSDIR}/devel/p5-Module-Pluggable-Ordered \
	p5-Data-Page>=2.00:${PORTSDIR}/databases/p5-Data-Page \
	p5-DateTime>=0.28:${PORTSDIR}/devel/p5-DateTime \
	p5-DBD-SQLite>=1.08:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-File-MMagic>=1.27:${PORTSDIR}/devel/p5-File-MMagic \
	p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
	p5-HTML-GenToc>=0:${PORTSDIR}/www/p5-HTML-GenToc \
	p5-HTML-Strip>=1.04:${PORTSDIR}/www/p5-HTML-Strip \
	p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
	p5-HTML-TagCloud>=0:${PORTSDIR}/www/p5-HTML-TagCloud \
	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
	p5-Image-Math-Constrain>=0:${PORTSDIR}/graphics/p5-Image-Math-Constrain \
	p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager \
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-IO>=1.14:${PORTSDIR}/devel/p5-IO \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
	p5-Pod-Simple>=3.01:${PORTSDIR}/textproc/p5-Pod-Simple \
	p5-String-Diff>=0:${PORTSDIR}/devel/p5-String-Diff \
	p5-Template-Plugin-JavaScript>=0:${PORTSDIR}/www/p5-Template-Plugin-JavaScript \
	p5-Text-Context>=3.5:${PORTSDIR}/textproc/p5-Text-Context \
	p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
	p5-XML-Clean>=0:${PORTSDIR}/textproc/p5-XML-Clean \
	p5-YAML>=0.36:${PORTSDIR}/textproc/p5-YAML \
	p5-URI-Fetch>=0:${PORTSDIR}/www/p5-URI-Fetch \
	p5-Text-Password-Pronounceable>=0:${PORTSDIR}/security/p5-Text-Password-Pronounceable \
	p5-DBIx-Class>=0.08:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-Syntax-Highlight-Engine-Kate>=0:${PORTSDIR}/textproc/p5-Syntax-Highlight-Engine-Kate \
	p5-Cache-FastMmap>=0:${PORTSDIR}/devel/p5-Cache-FastMmap \
	p5-Config-JFDI>=0:${PORTSDIR}/devel/p5-Config-JFDI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN1=	mojomojo_cgi.pl.1 \
	mojomojo_create.pl.1 \
	mojomojo_fastcgi.pl.1 \
	mojomojo_server.pl.1 \
	mojomojo_test.pl.1
MAN3=	MojoMojo.3 \
	MojoMojo::Controller::Admin.3 \
	MojoMojo::Controller::Attachment.3 \
	MojoMojo::Controller::Comment.3 \
	MojoMojo::Controller::Export.3 \
	MojoMojo::Controller::Gallery.3 \
	MojoMojo::Controller::JSON.3 \
	MojoMojo::Controller::Journal.3 \
	MojoMojo::Controller::Jsrpc.3 \
	MojoMojo::Controller::Page.3 \
	MojoMojo::Controller::PageAdmin.3 \
	MojoMojo::Controller::Root.3 \
	MojoMojo::Controller::Tag.3 \
	MojoMojo::Controller::User.3 \
	MojoMojo::Formatter.3 \
	MojoMojo::Formatter::Comment.3 \
	MojoMojo::Formatter::IRCLog.3 \
	MojoMojo::Formatter::Include.3 \
	MojoMojo::Formatter::Markdown.3 \
	MojoMojo::Formatter::Pod.3 \
	MojoMojo::Formatter::Redirect.3 \
	MojoMojo::Formatter::Scrub.3 \
	MojoMojo::Formatter::SyntaxHighlight.3 \
	MojoMojo::Formatter::TOC.3 \
	MojoMojo::Formatter::Textile.3 \
	MojoMojo::Formatter::Wiki.3 \
	MojoMojo::Installation.3 \
	MojoMojo::Model::DBIC.3 \
	MojoMojo::Model::Search.3 \
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
	MojoMojo::View::JSON.3 \
	MojoMojo::View::TT.3 \
	Text::SmartyPants.3 \
	Text::Textile2.3

post-extract:
	@${PERL} -i -ne 'print unless m,^feature,' ${WRKSRC}/Makefile.PL

OPTIONS=	DEPLOY "Automatic database deployment" Off \
		MARKDOWN "Markdown Formatter" Off

.include <bsd.port.pre.mk>

.if defined(WITH_DEPLOY)
RUN_DEPENDS+=	p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator
.endif
.if defined(WITH_MARKDOWN)
RUN_DEPENDS+=	p5-Text-Markdown>=1.0.17:${PORTSDIR}/textproc/p5-Text-Markdown
.endif

.include <bsd.port.post.mk>
