# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-webkit/Makefile,v 1.13 2011/03/06 23:12:41 kwm Exp $

PORTREVISION=	0
CATEGORIES=	net www
PKGNAMESUFFIX=	-webkit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	WebKit JavaScript plug-in for libproxy

LIB_DEPENDS=	libjavascriptcoregtk-3.0.so:www/webkit-gtk3 \
		libproxy.so:net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

ALL_TARGET=	pacrunner_webkit
USES=		pkgconfig

LIBPROXY_SLAVE=	webkit

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libproxy/${PORTVERSION}/modules/
	${INSTALL_LIB} ${BUILD_WRKSRC}/libproxy/pacrunner_webkit.so \
		${STAGEDIR}${PREFIX}/lib/libproxy/${PORTVERSION}/modules/

.include "${MASTERDIR}/Makefile"
