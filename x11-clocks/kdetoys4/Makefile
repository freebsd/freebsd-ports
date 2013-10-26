# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdetoys
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-clocks kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of entertaining programs for KDE

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdehier kdelibs kdeprefix workspace automoc4
USES=		cmake:outsource
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_XORG=	x11
USE_XZ=		yes

MAN6=	amor.6

NO_STAGE=	yes
.include <bsd.port.mk>
