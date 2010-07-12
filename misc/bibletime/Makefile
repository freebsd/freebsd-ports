# New ports collection makefile for:	bibletime-devel
# Date created:		2008-08-12
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	2.7.2
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/BibleTime%202/BibleTime%202%20source%20code

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	An opensource Bible study tool

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.6.1.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs \
		clucene.0:${PORTSDIR}/textproc/clucene

USE_OPENSSL=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui iconengines network phonon qtestlib script \
		svg webkit xml linguist_build moc_build qmake_build \
		rcc_build uic_build

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
CMAKE_USE_PTHREAD=	yes
.endif

CMAKE_BUILD_TYPE=	release

.include <bsd.port.post.mk>
