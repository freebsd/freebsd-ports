# New ports collection makefile for:	bibletime-devel
# Date created:		2008-08-12
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	2.9.0
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/BibleTime%202/BibleTime%202%20source%20code

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	An opensource Bible study tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.6.2.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	clucene.0:${PORTSDIR}/textproc/clucene

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui iconengines network phonon qtestlib script \
		svg webkit xml linguist_build moc_build qmake_build \
		rcc_build uic_build

.include <bsd.port.mk>
