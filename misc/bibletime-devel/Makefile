# New ports collection makefile for:	bibletime-devel
# Date created:		2008-08-12
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	1.7.a3
CATEGORIES=	misc kde
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/.alpha/}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A powerful Bible study application for KDE4

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.5.11.so:${PORTSDIR}/misc/sword \
		${LOCALBASE}/lib/libclucene.so:${PORTSDIR}/textproc/clucene
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python \
		phonon.4:${PORTSDIR}/multimedia/phonon

USE_BZIP2=	yes
USE_OPENSSL=	yes
KDE4_BUILDENV=	yes
USE_KDE4=	kdeprefix kdelibs workspace automoc4
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui xml

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${WRKDIR}/${PORTNAME}-${PORTVERSION}
	${MKDIR} ${WRKSRC}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} \
		-D CMAKE_BUILD_TYPE=Release \
		-D CMAKE_INSTALL_PREFIX=${PREFIX} \
		${WRKSRC}/..

.include <bsd.port.mk>
