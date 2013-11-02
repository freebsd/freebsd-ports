# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-gnome/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	1
CATEGORIES=	net devel
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME plug-in for libproxy

LIB_DEPENDS=	proxy.1:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_GNOME=	gconf2
USES=		pkgconfig

LIBPROXY_SLAVE=	gnome

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_LIB} ${WRKSRC}/libproxy/config_gnome.so \
		${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_PROGRAM} ${WRKSRC}/libproxy/pxgconf \
		${PREFIX}/libexec/

.include "${MASTERDIR}/Makefile"
