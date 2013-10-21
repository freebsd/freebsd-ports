# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nepomuk-core
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core Nepomuk system libraries and services for KDE

LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		tag.1:${PORTSDIR}/audio/taglib \
		exiv2.12:${PORTSDIR}/graphics/exiv2 \
		swscale:${PORTSDIR}/multimedia/ffmpeg

CONFLICTS_INSTALL=	kde-runtime-4.[7-8].*

USE_XZ=		yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs ontologies soprano
USES=		cmake:outsource
USE_QT4=	corelib dbus gui qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

SUB_FILES=	nepomuk-env.sh

NO_STAGE=	yes
post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/nepomuk-env.sh ${PREFIX}/env

.include <bsd.port.mk>
