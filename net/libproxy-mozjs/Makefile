# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-mozjs/Makefile,v 1.5 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	0
CATEGORIES=	net www
PKGNAMESUFFIX=	-mozjs

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla JavaScript plug-in for libproxy

LIB_DEPENDS=	libmozjs185.so:lang/spidermonkey185 \
		libproxy.so:net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

ALL_TARGET=	pacrunner_mozjs
USES=		pkgconfig

LIBPROXY_SLAVE=	mozjs

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_LIB} ${BUILD_WRKSRC}/libproxy/pacrunner_mozjs.so \
		${STAGEDIR}${PREFIX}/lib/libproxy/${PORTVERSION}/modules/

.include "${MASTERDIR}/Makefile"
