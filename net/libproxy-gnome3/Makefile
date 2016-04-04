# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net devel
PKGNAMESUFFIX=	-gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GSettings-based configuration plug-in for libproxy

LIB_DEPENDS=	libproxy.so:net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

ALL_TARGET=	config_gnome3 pxgsettings
USE_GNOME=	glib20
USES=		pkgconfig

LIBPROXY_SLAVE=	gnome3

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_LIB} ${BUILD_WRKSRC}/libproxy/config_gnome3.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libproxy/pxgsettings \
		${STAGEDIR}${PREFIX}/libexec/

.include "${MASTERDIR}/Makefile"
