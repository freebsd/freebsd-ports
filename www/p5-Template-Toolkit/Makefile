# New ports collection makefile for:	p5-Template-Toolkit
# Date Created:				3 Mar, 2001
# Whom:					clive
#
# $FreeBSD$
#

PORTNAME=	Template-Toolkit
PORTVERSION=	2.02
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MASTER_SITE_BACKUP+=	http://www.template-toolkit.org/download/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500007
BROKEN=	"Perl in base system too old, you need perl 5.6.0"
.endif

.if defined(BATCH)
CONFIGURE_ENV=	|
.endif

MAN1=	tpage.1 ttree.1
MAN3=	Template.3 Template::Base.3 Template::Constants.3 Template::Context.3 \
	Template::Document.3 Template::Exception.3 Template::FAQ.3 \
	Template::Filters.3 Template::Iterator.3 Template::Library::HTML.3 \
	Template::Library::PostScript.3 Template::Library::Splash.3 \
	Template::Manual.3 Template::Manual::Config.3 \
	Template::Manual::Credits.3 Template::Manual::Directives.3 \
	Template::Manual::Filters.3 Template::Manual::Internals.3 \
	Template::Manual::Intro.3 Template::Manual::Plugins.3 \
	Template::Manual::Refs.3 Template::Manual::Syntax.3 \
	Template::Manual::Variables.3 Template::Manual::Views.3 \
	Template::Modules.3 Template::Parser.3 Template::Plugin.3 \
	Template::Plugin::Autoformat.3 Template::Plugin::CGI.3 \
	Template::Plugin::DBI.3 Template::Plugin::Datafile.3 \
	Template::Plugin::Date.3 Template::Plugin::Directory.3 \
	Template::Plugin::Dumper.3 Template::Plugin::File.3 \
	Template::Plugin::Format.3 Template::Plugin::Iterator.3 \
	Template::Plugin::Pod.3 Template::Plugin::Table.3 \
	Template::Plugin::URL.3 Template::Plugin::View.3 \
	Template::Plugin::Wrap.3 Template::Plugin::XML::DOM.3 \
	Template::Plugin::XML::RSS.3 Template::Plugin::XML::Simple.3 \
	Template::Plugin::XML::XPath.3 Template::Plugins.3 \
	Template::Provider.3 Template::Service.3 Template::Stash.3 \
	Template::Test.3 Template::Tools::tpage.3 Template::Tools::ttree.3 \
	Template::Tutorial.3 Template::View.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${PERL} -pi -e 's,${LOCALBASE}/tt2,${LOCALBASE}/share/tt2,g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
