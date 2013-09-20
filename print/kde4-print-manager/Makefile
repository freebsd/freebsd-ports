# $FreeBSD$

PORTNAME=	print-manager
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer manager for KDE 4

LIB_DEPENDS=    cups.2:${PORTSDIR}/print/cups-client

USES=		cmake:outsource
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	network qmake_build moc_build uic_build rcc_build
USE_XZ=		yes

NO_STAGE=	yes
.include <bsd.port.mk>
