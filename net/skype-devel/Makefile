# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	1.1.0.20
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
DISTNAME=	skype_staticQT-${PORTVERSION}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

USE_BZIP2=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	Redistribution not allowed yet.

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier} != ""
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	${INSTALL} ${WRKSRC}/skype ${PREFIX}/bin/skype_bin
	${ECHO_CMD} -e "#!/bin/sh\n\nSKYPE_RESOURCES_PATH='${DATADIR}' exec skype_bin \"\$$@\"" >${PREFIX}/bin/skype
	${CHMOD} a+rx ${PREFIX}/bin/skype
.if ${HAVE_GNOME:Mgnomehier} != ""
	${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/gnome/applications/
	${INSTALL_DATA} ${WRKSRC}/icons/skype_48_32.png ${PREFIX}/share/gnome/pixmaps/skype.png
.endif
	${MKDIR} ${DATADIR}/icons ${DATADIR}/lang ${DATADIR}/sound
	${INSTALL_DATA} ${WRKSRC}/icons/* ${DATADIR}/icons/
	${INSTALL_DATA} ${WRKSRC}/lang/*.qm ${DATADIR}/lang/
	${INSTALL_DATA} ${WRKSRC}/sound/*.wav ${DATADIR}/sound/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DATADIR}/

post-install:
	@${ECHO} "##########################################################################"
	@${ECHO} "Do not worry if you see 'volume_adjust: SOUND_MIXER_WRITE_IGAIN failed: No such device or address' errors from skype, the skype sound code is overly verbose in this regard. It would be enough to print it only once." | fmt
	@${ECHO} "##########################################################################"
	@${ECHO} "There are known problems with some soundcards in 5.x. This is due to a bug in the kernel. It is fixed in 6.x. Additionally there is some further work in the sound subsystem going on which fixes some related problems. This work will not be available in 6.0-RELEASE. If you experience problems update to the most recent 6.x-RELEASE, if this does not fix your problems ask on multimedia@FreeBSD.org." | fmt

.include <bsd.port.post.mk>
