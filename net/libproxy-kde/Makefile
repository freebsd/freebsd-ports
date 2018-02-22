# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-kde/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	2
CATEGORIES=	net devel
PKGNAMESUFFIX=	-kde

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	KDE plug-in for libproxy

LIB_DEPENDS=	libproxy.so:net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

ALL_TARGET=	config_kde
USE_KDE=	runtime
USES+=		kde:4

LIBPROXY_SLAVE=	kde

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_LIB} ${BUILD_WRKSRC}/libproxy/config_kde.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/

.include "${MASTERDIR}/Makefile"
