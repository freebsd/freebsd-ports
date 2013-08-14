# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeadmin
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Admin applications

LATEST_LINK=	${PORTNAME}4

USE_XZ=		yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
USES=		cmake:outsource
USE_QT4=	dbus moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
