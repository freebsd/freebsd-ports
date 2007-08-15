# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	1.4.0.99
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
PKGNAMESUFFIX=	-devel
DISTNAME=	skype_static-${DISTVERSION}

MAINTAINER=	beech@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat \
		${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-alsa-lib \
		${LINUXBASE}/usr/lib/libsigc-2.0.so.0:${PORTSDIR}/devel/linux-libsigc++20

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_GL=	linux
.endif

BROKEN=	alsa sound not working
USE_BZIP2=	yes
USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	Redistribution not allowed

WRKSRC=		${WRKDIR}/${PORTNAME}_static-${DISTVERSION}
DATADIR=	${PREFIX}/share/${PKGBASE}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} ${WRKSRC}/skype ${PREFIX}/bin/skype-devel_bin
	@${ECHO_CMD} -e "#!/bin/sh\n\nSKYPE_RESOURCES_PATH='${DATADIR}' skype-devel_bin \"\$$@\" 2>&1 | ${GREP} -v 'SOUND_MIXER_WRITE_IGAIN failed'" >${PREFIX}/bin/skype-devel
	@${CHMOD} a+rx ${PREFIX}/bin/skype-devel
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "icons sounds LICENSE README" ${DATADIR}/
	@${ECHO} "There are known problems with some soundcards in 5.x. This is due to a bug in the kernel. It is fixed in 6.x. Additionally there is some further work in the sound subsystem going on which fixes some related problems. This work will not be available in 6.0-RELEASE. If you experience problems update to the most recent 6.x-RELEASE, if this does not fix your problems ask on multimedia@FreeBSD.org." | fmt

.include <bsd.port.mk>
