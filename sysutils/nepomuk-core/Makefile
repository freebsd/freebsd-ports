# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		nepomuk-core
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		sysutils kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Core Nepomuk system libraries and services for KDE

CONFLICTS_INSTALL=	kde-runtime-4.[7-8].*

USE_XZ=			yes
USE_KDE4=		kdeprefix kdehier automoc4 kdelibs \
			ontologies soprano strigi
KDE4_BUILDENV=		yes
USE_QT4=		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=		yes

SUB_FILES=		nepomuk-env.sh

post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/nepomuk-env.sh ${PREFIX}/env

.include <bsd.port.mk>
