# New ports collection makefile for:	libproxy-webkit
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	net devel
PKGNAMESUFFIX=	-webkit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	WebKit Javascript plug-in for libproxy

LIB_DEPENDS=	proxy.0:${PORTSDIR}/net/libproxy \
    		webkit-1.0.1:${PORTSDIR}/www/webkit-gtk2

MASTERDIR=	${.CURDIR}/../libproxy
BUILD_WRKSRC=	${WRKSRC}/src/plugins
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
CONFIGURE_ARGS=--without-gnome --without-kde --with-webkit \
		--without-mozjs --without-networkmanager --without-python \
		--without-envvar --without-file

LIBPROXY_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
