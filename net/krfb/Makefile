# $FreeBSD$

PORTNAME=	krfb
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdenetwork-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VNC server for KDE

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		telepathy-qt4.2:${PORTSDIR}/net-im/telepathy-qt4

DISTINFO_FILE=	${.CURDIR}/../../net/kdenetwork4/distinfo

CONFLICTS_INSTALL=	kdenetwork-4.[1-8].*

USE_CMAKE=	yes
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
MAKE_JOBS_SAFE=	yes

CMAKE_OUTSOURCE=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
