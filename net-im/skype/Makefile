# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	0.92.0.12
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
DISTNAME=	skype_staticQT-${PORTVERSION}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=	${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat \
		${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

USE_BZIP2=	yes
USE_X_PREFIX=	yes
#USE_LINUX=	yes
WANT_GNOME=	yes
ONLY_FOR_ARCHS=	i386

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
	${INSTALL} ${WRKSRC}/skype ${PREFIX}/bin/
.if ${HAVE_GNOME:Mgnomehier} != ""
	${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/gnome/applications/
	${INSTALL_DATA} ${WRKSRC}/icons/skype_48_32.png ${PREFIX}/share/gnome/pixmaps/skype.png
.endif
	${MKDIR} ${DATADIR}/icons ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/icons/* ${DATADIR}/icons/
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}/lang/
	${INSTALL_DATA} ${WRKSRC}/call_in.wav ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DATADIR}/

post-install:
	@${ECHO} "##########################################################################"
	@${ECHO} "Since skype uses a hadcoded path to the data/language files (/usr/share/skype and .../lang) which a port isn't allowed to install files into, call_in.wav and the language files are not installed into the official path and therefore are not usable out of the box." | fmt
	@${ECHO}
	@${ECHO} "Known good soundcards for the use with Skype:"
	@${ECHO} " - SiS 7012 (snd_ich) based ones"
	@${ECHO} " - CMedia CMI8738 (snd_cmi) based ones"
	@${ECHO} " - Creative EMU10K1 (snd_emu10k1) based ones"
	@${ECHO}
	@${ECHO} "Probably bad soundcards for the use with Skype:"
	@${ECHO} " - VIA on-board sound (FreeBSD 5.1 seems to be ok)"
	@${ECHO} " - Creative CT5880 (snd_es137x) based ones"
	@${ECHO} " - Yamaha DS-1E (snd_ds1) based ones (reported for FreeBSD 4.10)"
	@${ECHO}
	@${ECHO} "If your soundcard is not listed here, send the the output of 'cat /dev/sndstat' with a short note if it works or not to ${MAINTAINER} please." | fmt
	@${ECHO} "##########################################################################"

.include <bsd.port.post.mk>
