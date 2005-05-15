# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	1.0.0.20
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
DISTNAME=	skype_staticQT-${PORTVERSION}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat \
		${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
WANT_GNOME=	yes
ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	Redistribution not allowed yet.

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier} != ""
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

#WRKSRC= ${WRKDIR}/${DISTNAME}

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
	@${ECHO} "Known good soundcards for the use with Skype:"
	@${ECHO} " - SiS 7012 (snd_ich) based ones"
	@${ECHO} " - CMedia CMI8738 (snd_cmi) based ones"
	@${ECHO} " - Creative EMU10K1 (snd_emu10k1) based ones"
	@${ECHO}
	@${ECHO} "Probably bad soundcards for the use with Skype:"
	@${ECHO} " - VIA on-board sound (FreeBSD 5.1 seems to be ok)"
	@${ECHO} " - Creative CT5880 (snd_es137x) based ones"
	@${ECHO} " - Yamaha DS-1E (snd_ds1) based ones (reported for FreeBSD 4.10)"
	@${ECHO} " - SB16 DSP 4.16 (snd_sb16) based ones"
	@${ECHO} " - ESS 18xx (snd_ess) based ones"
	@${ECHO} " - Acer Labs M5451 (snd_t4dwave) based ones"
	@${ECHO}
	@${ECHO} "If your soundcard is not listed here, send the the output of 'cat /dev/sndstat' with a short note if it works or not to ${MAINTAINER} please." | fmt
	@${ECHO} "##########################################################################"

.include <bsd.port.post.mk>
