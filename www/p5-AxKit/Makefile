# Ports collection Makefile for:		AxKit
# Date created:					17 Jan 2001
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit
PORTVERSION=	1.5
CATEGORIES=	www
MASTER_SITES=	http://www.axkit.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv
BUILD_DEPENDS=	\
		${SITE_PERL}/${PERL_ARCH}/Apache/libapreq.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		\
		Apache::AxKit::Language.3 \
		Apache::AxKit::Language::XPathScript.3 \
		Apache::AxKit::Language::XSP.3 \
		Apache::AxKit::Language::XSP::TaglibHelper.3 \
		Apache::AxKit::Plugins::Fragment.3 \
		Apache::AxKit::Plugins::Passthru.3 \
		Apache::AxKit::Provider.3 \
		Apache::AxKit::StyleChooser::Cookie.3 \
		Apache::AxKit::StyleChooser::FileSuffix.3 \
		Apache::AxKit::StyleChooser::PathInfo.3 \
		Apache::AxKit::StyleChooser::QueryString.3 \
		Apache::AxKit::StyleChooser::UserAgent.3 \
		Apache::MimeXML.3 \
		AxKit.3

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2' \
		LIBS='-L${LOCALBASE}/lib'

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL \
		OPTIMIZE="${CFLAGS}" \
		INC="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/include"

EX_DIR=${PREFIX}/share/examples/${PORTNAME}
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EX_DIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EX_DIR}
	${CP} -R ${WRKSRC}/axkit.org ${EX_DIR}
.endif

.include <bsd.port.mk>
