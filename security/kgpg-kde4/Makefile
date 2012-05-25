# New ports collection Makefile for:	kdeutils
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kgpg
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	security kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Encryption tool for KDE

RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

CONFLICTS_INSTALL_INSTALL=	kdeutils-4.[0-7].*
LATEST_LINK=	${PORTNAME}4

USE_XZ=	yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs pimlibs
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
