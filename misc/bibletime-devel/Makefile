# New ports collection makefile for:	bibletime-devel
# Date created:		2009-03-23
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	2.0.r1
CATEGORIES=	misc kde
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/.rc/}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	An opensource Bible study application

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.5.11.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python \
		clucene.0:${PORTSDIR}/textproc/clucene

USE_OPENSSL=	yes
KDE4_BUILDENV=	yes
USE_KDE4=	kdeprefix runtime workspace automoc4
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui xml webkit qmake_build moc_build uic_build rcc_build

CONFLICTS=	bibletime*-1.7*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=	does on build on 6.x, use misc/bibletime-kde3
.endif

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${WRKDIR}/${PORTNAME}-${PORTVERSION}
	${MKDIR} ${WRKSRC}/build

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} \
		-D CMAKE_BUILD_TYPE=Release \
		-D CMAKE_INSTALL_PREFIX=${PREFIX} \
		${WRKSRC}/..

.include <bsd.port.post.mk>
