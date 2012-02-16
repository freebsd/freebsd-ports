# New ports collection makefile for:	libproxy-kde
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/libproxy-kde/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	1
CATEGORIES=	net devel
PKGNAMESUFFIX=	-kde

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	KDE plug-in for libproxy

LIB_DEPENDS=	proxy.1:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_QT_VER=	4
QT_COMPONENTS=	corelib moc_build qmake_build uic_build rcc_build
USE_KDE4=	automoc4 kdelibs

LIBPROXY_SLAVE=	kde

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_LIB} ${WRKSRC}/lib/config_kde4.so \
		${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/

.include "${MASTERDIR}/Makefile"
