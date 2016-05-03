# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opentoken
PORTVERSION=	6.0b
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://stephe-leake.org/ada/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Lexical analyser and parser for the Ada language

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	gprbuild>=20130416:devel/gprbuild

USES=		ada tar:bzip2

WRKSRC=		${WRKDIR}/org.${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/build/release
OTLIBVER=	5.0.0
PLIST_SUB+=	OTLIBVER=${OTLIBVER}

do-build:
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		gprbuild -p -P opentoken_lib )

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/opentoken \
		${STAGEDIR}${PREFIX}/include/opentoken
	${INSTALL_DATA} ${BUILD_WRKSRC}/lib/*.ali \
		${STAGEDIR}${PREFIX}/lib/opentoken
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/libopentoken.so.${OTLIBVER} \
		${STAGEDIR}${PREFIX}/lib/opentoken
	(cd ${STAGEDIR}${PREFIX}/lib/opentoken && \
		${LN} -s libopentoken.so.${OTLIBVER} libopentoken.so)
	${INSTALL_DATA} ${WRKSRC}/*.ad[bs] ${WRKSRC}/Language_Lexers/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/opentoken
	${INSTALL_DATA} ${FILESDIR}/opentoken.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
