# $FreeBSD$

PORTNAME=	analitza
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library from KDE Education project

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib gui opengl svg xml \
		moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_LDCONFIG=	yes

.include <bsd.port.mk>
