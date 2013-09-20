# $FreeBSD$

PORTNAME=	libkdeedu
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries used by KDE educational applications

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource
USE_QT4=	corelib gui xml moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
