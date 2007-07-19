# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	1.3.0.30
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
PKGNAMESUFFIX=	-devel
DISTNAME=	skype-beta_staticQT-${PORTVERSION}

MAINTAINER=	beech@FreeBSD.org
COMMENT=	P2P VoIP software

CONFLICTS=	skype-[0-9]*

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat \
		${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-alsa-lib

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

BROKEN=	sources not available

USE_BZIP2=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	Redistribution not allowed yet.

.include <bsd.port.pre.mk>

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL} ${WRKSRC}/skype ${PREFIX}/bin/skype_bin
#	${INSTALL} ${WRKSRC}/skype-callto-handler ${PREFIX}/bin/
	${ECHO_CMD} -e "#!/bin/sh\n\nSKYPE_RESOURCES_PATH='${DATADIR}' skype_bin \"\$$@\" 2>&1 | ${GREP} -v 'SOUND_MIXER_WRITE_IGAIN failed'" >${PREFIX}/bin/skype
	${CHMOD} a+rx ${PREFIX}/bin/skype
	${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/icons/skype_48_32.png ${PREFIX}/share/pixmaps/skype.png
	${MKDIR} ${DATADIR}/icons ${DATADIR}/lang ${DATADIR}/sound
	${INSTALL_DATA} ${WRKSRC}/icons/* ${DATADIR}/icons/
	${INSTALL_DATA} ${WRKSRC}/lang/*.qm ${DATADIR}/lang/
	${INSTALL_DATA} ${WRKSRC}/sound/*.wav ${DATADIR}/sound/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DATADIR}/

post-install:
	@${ECHO} "There are known problems with some soundcards in 5.x. This is due to a bug in the kernel. It is fixed in 6.x. Additionally there is some further work in the sound subsystem going on which fixes some related problems. This work will not be available in 6.0-RELEASE. If you experience problems update to the most recent 6.x-RELEASE, if this does not fix your problems ask on multimedia@FreeBSD.org." | fmt

.include <bsd.port.post.mk>
