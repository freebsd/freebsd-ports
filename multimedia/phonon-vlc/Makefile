# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	0.6.2
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}
PKGNAMESUFFIX=	-vlc
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon

LIB_DEPENDS=	vlc:${PORTSDIR}/multimedia/vlc

# Required in order to avoid conflicts with multimedia/phonon.
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USE_KDE4=	kdehier kdeprefix automoc4
USE_QT4=	corelib gui phonon \
		qmake_build moc_build rcc_build uic_build
USE_XZ=		yes
USES=		cmake
MAKE_JOBS_SAFE=	yes

PHONON_BRANCH=	stable

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

pre-su-install:
	${MKDIR} ${QT_PLUGINDIR}/phonon_backend

post-install:
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so ${QT_PLUGINDIR}/phonon_backend/libphonon_vlc.so

.include <bsd.port.mk>
