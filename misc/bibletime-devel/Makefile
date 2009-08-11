# New ports collection makefile for:	bibletime-devel
# Date created:		2009-03-23
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bibletime
DISTVERSION=	2.1-20090623
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	tabthorpe
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/.rc/}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	An opensource Bible study tool

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.6.0.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs \
		clucene.0:${PORTSDIR}/textproc/clucene

IGNORE=		Use misc/bibletime-kde4
EXPIRATION_DATE=	2009-08-16

USE_OPENSSL=	yes
KDE4_BUILDENV=	yes
USE_KDE4=	kdeprefix runtime workspace automoc4
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui xml webkit qmake_build moc_build uic_build rcc_build

CMAKE_SOURCE_PATH=	${WRKSRC}/..

CONFLICTS=	bibletime-kde4-2*

.include <bsd.port.mk>
