# $FreeBSD$

PORTNAME=	libhijack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0-2
DISTVERSIONSUFFIX=	-g972534d
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Runtime process infection made easy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

USE_GITHUB=	yes
GH_ACCOUNT=	SoldierX
USE_LDCONFIG=	yes

PLIST_FILES=	include/hijack.h \
		lib/libhijack.so \
		lib/libhijack.so.2 \
		sbin/hijack

do-install: # the original install fails: https://github.com/SoldierX/libhijack/issues/6
	${INSTALL_DATA} ${WRKSRC}/include/hijack.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libhijack/obj/libhijack.so* ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/hijack/obj/hijack ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
