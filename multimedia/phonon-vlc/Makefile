# New ports collection makefile for:	phonon-vlc
# Date created:		2010-07-25
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phonon
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-vlc
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon

# Required in order to avoid conflicts with multimedia/phonon.
LATEST_LINK=    ${PORTNAME}${PKGNAMESUFFIX}

LIB_DEPENDS=	vlc:${PORTSDIR}/multimedia/vlc

PHONON_BRANCH=	stable

USE_KDE4=	kdehier kdeprefix automoc4
USE_QT4=	gui phonon \
		qmake_build moc_build rcc_build uic_build
USE_XZ=		yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

pre-su-install:
	${MKDIR} ${QT_PLUGINDIR}/phonon_backend

post-install:
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so ${QT_PLUGINDIR}/phonon_backend/libphonon_vlc.so

.include <bsd.port.mk>
