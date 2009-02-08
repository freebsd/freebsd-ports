# New ports collection Makefile for:	kdemultimedia
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
		ogg.5:${PORTSDIR}/audio/libogg \
		tag.6:${PORTSDIR}/audio/taglib \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp \
		xine.1:${PORTSDIR}/multimedia/libxine
RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools \
		lame:${PORTSDIR}/audio/lame

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support designer network svg qtestlib \
		qmake_build moc_build rcc_build uic_build
USE_OPENLDAP=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CMAKE_USE_PTHREAD+= yes
.endif

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
