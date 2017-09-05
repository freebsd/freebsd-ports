# Created by: gahr
# $FreeBSD$

PORTNAME=	xerces-c
PORTVERSION=	3.2.0
CATEGORIES=	textproc
MASTER_SITES=	APACHE/xerces/c/3/sources
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--enable-netaccessor-socket \
		--enable-transcoder-iconv \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ENV=	XERCESCROOT=${WRKSRC}
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		cpe gmake iconv libtool pathfix

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R}

CPE_PRODUCT=	xerces-c++
CPE_VENDOR=	apache

post-patch:
	${REINPLACE_CMD} -e "s,@DEFS@,& -D__STDC_LIMIT_MACROS," ${WRKSRC}/src/Makefile.in
	
post-install:
	${LN} -s libxerces-c-${PORTVERSION:R}.so ${STAGEDIR}${PREFIX}/lib/libxerces-c.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
