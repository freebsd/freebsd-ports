# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	0.91.0.3
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
DISTNAME=	skype_ver-${PORTVERSION:C/\./_/g}-staticQT

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat \
		${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

USE_BZIP2=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
ONLY_FOR_ARCHS=	i386

RESTRICTED=	Redistribution not allowed yet.

.if defined(PACKAGE_BUILDING)
IGNORE=		conflicts between linux_base and linux_base-8
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier} != ""
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

WRKSRC=	${WRKDIR}/skype_ver_${PORTVERSION:C/\./_/g}-staticQT

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	${INSTALL} ${WRKSRC}/skype ${PREFIX}/bin/
.if ${HAVE_GNOME:Mgnomehier} != ""
	${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/gnome/applications/
	${INSTALL_DATA} ${WRKSRC}/icons/skype_48_32.png ${PREFIX}/share/gnome/pixmaps/skype.png
.endif
	${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/* ${DATADIR}/icons/
	${INSTALL_DATA} ${WRKSRC}/call_in.wav ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DATADIR}/

post-install:
	@${ECHO} "Since skype uses a hadcoded path to the language files (/usr/share/skype) which a port isn't allowed to install files into, call_in.wav and the language files are not installed. As soon as skype learns how to use other paths, this will change." | fmt

.include <bsd.port.post.mk>
