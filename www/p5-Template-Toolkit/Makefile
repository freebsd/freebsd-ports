# New ports collection makefile for:	p5-Template-Toolkit
# Date Created:				3 Mar, 2001
# Whom:					clive
#
# $FreeBSD$
#

PORTNAME=	Template-Toolkit
PORTVERSION=	2.14
PORTREVISION=	2
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensive Toolkit for template processing

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=TEXT_AUTOFORMAT "With Text::Autoformat Plugin"		off \
	GD		"With GD Plugin (needs perl5.6)"	off \
	GD_TEXT		"With GD::Text Plugin (needs GD)"	off \
	GD_GRAPH	"With GD::Graph Plugin (needs GD)"	off \
	GD_GRAPH3D	"With GD::Graph3d Plugin (needs GD)"	off \
	IMAGE_INFO	"With Image::Info Plugin"		off \
	IMAGE_SIZE	"With Image::Size Plugin"		off \
	DATE_CALC	"With Date::Calc Plugin"		off \
	POD_POM		"With Pod::POM Plugin"			off \
	TIE_DBI		"With Tie::DBI Plugin"			off \
	XML_DOM		"With XML::DOM Plugin"			off \
	XML_RSS		"With XML::RSS Plugin (needs perl5.6)"	off \
	XML_XPATH	"With XML::XPath Plugin"		off \
	DBI		"With DBI Plugin"			off

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	TT_DBI=n TT_ACCEPT=y

MASTER_SITE_BACKUP+=	http://www.template-toolkit.org/download/

.include <bsd.port.pre.mk>

.if defined(WITH_TEXT_AUTOFORMAT)
BUILD_DEPENDS+=${SITE_PERL}/Text/Autoformat.pm:${PORTSDIR}/textproc/p5-Text-Autoformat
.endif
.if defined(WITH_IMAGE_INFO)
BUILD_DEPENDS+=${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info
.endif
.if defined(WITH_IMAGE_SIZE)
BUILD_DEPENDS+=${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size
.endif
.if defined(WITH_DATE_CALC)
BUILD_DEPENDS+=${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc
.endif
.if defined(WITH_POD_POM)
BUILD_DEPENDS+=${SITE_PERL}/Pod/POM.pm:${PORTSDIR}/textproc/p5-Pod-POM
.endif
.if defined(WITH_TIE_DBI)
BUILD_DEPENDS+=${SITE_PERL}/Tie/DBI.pm:${PORTSDIR}/databases/p5-Tie-DBI
.endif
.if defined(WITH_XML_DOM)
BUILD_DEPENDS+=${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM
.endif
.if defined(WITH_XML_XPATH)
BUILD_DEPENDS+=${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath
.endif

.if defined(WITH_DBI)
.if ${PERL_LEVEL} > 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.endif
.endif

.if ${PERL_LEVEL} > 500600
.if defined(WITH_GD)
BUILD_DEPENDS+=${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
.endif
.if defined(WITH_GD_TEXT)
BUILD_DEPENDS+=${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
.endif
.if defined(WITH_GD_GRAPH)
BUILD_DEPENDS+=${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
.endif
.if defined(WITH_GD_GRAPH3D)
BUILD_DEPENDS+=${SITE_PERL}/GD/Graph3d.pm:${PORTSDIR}/graphics/p5-GD-Graph3d
.endif
.if defined(WITH_XML_RSS)
BUILD_DEPENDS+=${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS
.endif
.endif

.if defined(BATCH)
CONFIGURE_ENV=	|
.endif

MAN1=	tpage.1 ttree.1
MAN3=	Template.3 \
	Template::Base.3 \
	Template::Constants.3 \
	Template::Context.3 \
	Template::Document.3 \
	Template::Exception.3 \
	Template::FAQ.3 \
	Template::Filters.3 \
	Template::Iterator.3 \
	Template::Library::HTML.3 \
	Template::Library::PostScript.3 \
	Template::Library::Splash.3 \
	Template::Manual.3 \
	Template::Manual::Config.3 \
	Template::Manual::Credits.3 \
	Template::Manual::Directives.3 \
	Template::Manual::Filters.3 \
	Template::Manual::Internals.3 \
	Template::Manual::Intro.3 \
	Template::Manual::Plugins.3 \
	Template::Manual::Refs.3 \
	Template::Manual::Syntax.3 \
	Template::Manual::VMethods.3 \
	Template::Manual::Variables.3 \
	Template::Manual::Views.3 \
	Template::Modules.3 \
	Template::Namespace::Constants.3 \
	Template::Parser.3 \
	Template::Plugin.3 \
	Template::Plugin::Autoformat.3 \
	Template::Plugin::CGI.3 \
	Template::Plugin::DBI.3 \
	Template::Plugin::Datafile.3 \
	Template::Plugin::Date.3 \
	Template::Plugin::Directory.3 \
	Template::Plugin::Dumper.3 \
	Template::Plugin::File.3 \
	Template::Plugin::Filter.3 \
	Template::Plugin::Format.3 \
	Template::Plugin::GD::Constants.3 \
	Template::Plugin::GD::Graph::area.3 \
	Template::Plugin::GD::Graph::bars.3 \
	Template::Plugin::GD::Graph::bars3d.3 \
	Template::Plugin::GD::Graph::lines.3 \
	Template::Plugin::GD::Graph::lines3d.3 \
	Template::Plugin::GD::Graph::linespoints.3 \
	Template::Plugin::GD::Graph::mixed.3 \
	Template::Plugin::GD::Graph::pie.3 \
	Template::Plugin::GD::Graph::pie3d.3 \
	Template::Plugin::GD::Graph::points.3 \
	Template::Plugin::GD::Image.3 \
	Template::Plugin::GD::Polygon.3 \
	Template::Plugin::GD::Text.3 \
	Template::Plugin::GD::Text::Align.3 \
	Template::Plugin::GD::Text::Wrap.3 \
	Template::Plugin::HTML.3 \
	Template::Plugin::Image.3 \
	Template::Plugin::Iterator.3 \
	Template::Plugin::Pod.3 \
	Template::Plugin::Procedural.3 \
	Template::Plugin::String.3 \
	Template::Plugin::Table.3 \
	Template::Plugin::URL.3 \
	Template::Plugin::View.3 \
	Template::Plugin::Wrap.3 \
	Template::Plugin::XML::DOM.3 \
	Template::Plugin::XML::RSS.3 \
	Template::Plugin::XML::Simple.3 \
	Template::Plugin::XML::Style.3 \
	Template::Plugin::XML::XPath.3 \
	Template::Plugins.3 \
	Template::Provider.3 \
	Template::Service.3 \
	Template::Stash.3 \
	Template::Stash::Context.3 \
	Template::Stash::XS.3 \
	Template::Test.3 \
	Template::Tools::tpage.3 \
	Template::Tools::ttree.3 \
	Template::Tutorial.3 \
	Template::Tutorial::Datafile.3 \
	Template::Tutorial::Web.3 \
	Template::View.3

post-patch:
	${PERL} -pi -e 's,/usr/local/tt2,${PREFIX}/share/tt2,g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if ${PERL_LEVEL} < 500601
	${FIND} ${WRKSRC} -name '*.orig' -delete

EXTRA_PATCHES=	${PATCHDIR}/5.005-lib-Template-Document.pm
.endif

.if ${PERL_LEVEL} >= 500800
MAN3+=	Template::Config.3
.endif

.include <bsd.port.post.mk>
