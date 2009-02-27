# New ports collection makefile for:	libproxy-kde
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	net devel
PKGNAMESUFFIX=	-kde

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	KDE plug-in for libproxy

LIB_DEPENDS=	proxy.0:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
BUILD_WRKSRC=	${WRKSRC}/src/plugins
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_XORG=	xmu x11
CONFIGURE_ARGS=--without-gnome --with-kde --without-webkit \
		--without-mozjs --without-networkmanager --without-python \
		--without-envvar --without-file

LIBPROXY_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
