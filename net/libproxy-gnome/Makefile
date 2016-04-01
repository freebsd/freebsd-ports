# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-gnome/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	0
CATEGORIES=	net devel
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GConf-based plug-in for libproxy

LIB_DEPENDS=	libproxy.so:net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

ALL_TARGET=	config_gnome pxgconf
USE_GNOME=	gconf2 glib20
USES=		pkgconfig

LIBPROXY_SLAVE=	gnome

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_LIB} ${BUILD_WRKSRC}/libproxy/config_gnome.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libproxy/pxgconf \
		${STAGEDIR}${PREFIX}/libexec/

.include "${MASTERDIR}/Makefile"
