# $FreeBSD$

PORTNAME=	baloo-widgets
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The BalooWidgets library

USE_KDE4=	automoc4 baloo kfilemetadata

USES=		cmake:outsource tar:xz
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
