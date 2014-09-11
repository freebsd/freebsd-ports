# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-kde/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	5
CATEGORIES=	net devel
PKGNAMESUFFIX=	-kde

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	KDE plug-in for libproxy

LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_QT4=	corelib moc_build qmake_build uic_build rcc_build
USE_KDE4=	automoc4 kdelibs

LIBPROXY_SLAVE=	kde

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/
	${INSTALL_LIB} ${WRKSRC}/lib/config_kde4.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/modules/

.include "${MASTERDIR}/Makefile"
