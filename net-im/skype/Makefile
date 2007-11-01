# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	1.2.0.18
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	NETBSD
DISTNAME=	skype_staticQT-${PORTVERSION}

MAINTAINER=	beech@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

USE_BZIP2=	yes
USE_LINUX=	yes

RESTRICTED=	Redistribution prohibited.

OPTIONS=	NVIDIA_GL "Enable Nvidia Support" off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/bin/skype_bin
	@${ECHO_CMD} -e "#!/bin/sh\n\nSKYPE_RESOURCES_PATH='${DATADIR}' skype_bin \"\$$@\" 2>&1 | grep -v 'SOUND_MIXER_WRITE_IGAIN failed'" >${PREFIX}/bin/skype
	@${CHMOD} a+rx ${PREFIX}/bin/skype
	@${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/skype_48_32.png ${PREFIX}/share/pixmaps/skype.png
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "icons sound lang LICENSE" ${DATADIR}/
	@${ECHO} "There are known problems with some soundcards in 5.x. This is due to a bug in the kernel. It is fixed in 6.x. Additionally there is some further work in the sound subsystem going on which fixes some related problems. This work will not be available in 6.0-RELEASE. If you experience problems update to the most recent RELEASE, if this does not fix your problems ask on multimedia@FreeBSD.org." | fmt

.include <bsd.port.post.mk>
