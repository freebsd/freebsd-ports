# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-webkit/Makefile,v 1.13 2011/03/06 23:12:41 kwm Exp $

PORTREVISION=	3
CATEGORIES=	net www
PKGNAMESUFFIX=	-webkit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	WebKit JavaScript plug-in for libproxy

LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USES=		pkgconfig

LIBPROXY_SLAVE=	webkit

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libproxy/${PORTVERSION}/modules/
	${INSTALL_LIB} ${WRKSRC}/libproxy/pacrunner_webkit.so \
		${STAGEDIR}${PREFIX}/lib/libproxy/${PORTVERSION}/modules/

.include "${MASTERDIR}/Makefile"
