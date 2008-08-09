# New ports collection Makefile for:	kdemultimedia
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications

LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile \
		FLAC:${PORTSDIR}/audio/flac \
		cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		ogg:${PORTSDIR}/audio/libogg \
		tag:${PORTSDIR}/audio/taglib \
		theora:${PORTSDIR}/multimedia/libtheora \
		vorbis:${PORTSDIR}/audio/libvorbis \
		mp3lame:${PORTSDIR}/audio/lame \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp \
		xine.1:${PORTSDIR}/multimedia/libxine
RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl moc rcc uic dbus qt3support designer network svg qtestlib
USE_OPENLDAP=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CMAKE_USE_PTHREAD+= yes
.endif

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
