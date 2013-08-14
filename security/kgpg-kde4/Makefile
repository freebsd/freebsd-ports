# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kgpg
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	security kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Encryption tool for KDE

RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

CONFLICTS_INSTALL_INSTALL=	kdeutils-4.[0-7].*
LATEST_LINK=	${PORTNAME}4

USE_XZ=		yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs pimlibs
USES=		cmake:outsource
USE_QT4=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
