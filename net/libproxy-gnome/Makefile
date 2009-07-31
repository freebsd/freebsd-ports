# New ports collection makefile for:	libproxy-gnome
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	net devel
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME plug-in for libproxy

LIB_DEPENDS=	proxy.0:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
BUILD_WRKSRC=	${WRKSRC}/src/plugins
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_XORG=	xmu x11
USE_GNOME=	gconf2
CONFIGURE_ARGS=--with-gnome --without-kde --without-webkit \
		--without-mozjs --without-networkmanager --without-python \
		--without-envvar --without-file

LIBPROXY_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
