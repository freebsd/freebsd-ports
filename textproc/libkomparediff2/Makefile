# $FreeBSD$

PORTNAME=	libkomparediff2
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	textproc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to compare files and strings

USES=		cmake:outsource tar:xz
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
