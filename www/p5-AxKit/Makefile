# Ports collection Makefile for:		AxKit
# Date created:					17 Jan 2001
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit
PORTVERSION=	1.6.2
CATEGORIES=	www
MASTER_SITES=	http://www.axkit.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	adam@migus.org
COMMENT=	XML Delivery Toolkit for Apache/Perl

BUILD_DEPENDS=	\
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/${PERL_ARCH}/Apache/libapreq.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		${SITE_PERL}/${PERL_ARCH}/XML/Sablotron.pm:${PORTSDIR}/textproc/p5-XML-Sablotron \
		${SITE_PERL}/Perl/Tidy.pm:${PORTSDIR}/devel/perltidy \
		${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-1.62

MAN3=		\
		Apache::AxKit::Language.3 \
		Apache::AxKit::Language::AxPoint.3 \
		Apache::AxKit::Language::HtmlDoc.3 \
		Apache::AxKit::Language::SAXMachines.3 \
		Apache::AxKit::Language::XPathScript.3 \
		Apache::AxKit::Language::XSP.3 \
		Apache::AxKit::Language::XSP::SimpleTaglib.3 \
		Apache::AxKit::Language::XSP::TaglibHelper.3 \
		Apache::AxKit::LibXMLSupport.3 \
		Apache::AxKit::MediaChooser::WAPCheck.3 \
		Apache::AxKit::Plugin::Fragment.3 \
		Apache::AxKit::Plugin::Passthru.3 \
		Apache::AxKit::Plugin::QueryStringCache.3 \
		Apache::AxKit::Provider.3 \
		Apache::AxKit::Provider::FileWrite.3 \
		Apache::AxKit::StyleChooser::Cookie.3 \
		Apache::AxKit::StyleChooser::FileSuffix.3 \
		Apache::AxKit::StyleChooser::PathInfo.3 \
		Apache::AxKit::StyleChooser::QueryString.3 \
		Apache::AxKit::StyleChooser::UserAgent.3 \
		AxKit.3

USE_ICONV=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2' \
		LIBS='-L${LOCALBASE}/lib' \
		OPTIMIZE="${CFLAGS}"
CONFIGURE_ENV+=	PERL_EXTUTILS_AUTOINSTALL='--defaultdeps'

EX_DIR=${PREFIX}/share/examples/${PORTNAME}
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EX_DIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EX_DIR}
	${CP} -R ${WRKSRC}/axkit.org ${EX_DIR}
.endif

.include <bsd.port.mk>
