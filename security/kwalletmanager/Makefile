# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kwalletmanager
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	security kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Password manager for KDE

USES=		cmake:outsource gmake kde:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT4=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
