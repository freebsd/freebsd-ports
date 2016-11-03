# Created by: netchild@FreeBSD.org
# $FreeBSD$

PORTNAME=	skype
PORTVERSION=	2.2.0.35
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://download.skype.com/linux/
PKGNAMESUFFIX=	-devel
DISTNAME=	skype_static-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	P2P VoIP software, development version

CONFLICTS=	skype-[0-9]*

OPTIONS_DEFINE=	VIDEO
OPTIONS_DEFAULT=VIDEO
VIDEO_DESC=	[broken] Video support

CONFLICTS=	skype-1* skype-2.0* skype-2.1*

NO_BUILD=	yes

USES=		cpe linux tar:bzip2
USE_LINUX=	alsalib alsa-plugins-oss dri expat fontconfig libasyncns \
		libsigcpp20 xorglibs
RESTRICTED=	Redistribution prohibited.

WRKSRC=		${WRKDIR}/${PORTNAME}_static-${DISTVERSION}
SKYPEDIR=	share/skype
PORTDOCS=	LICENSE README
PLIST_SUB+=	SKYPEDIR=${SKYPEDIR}
SUB_FILES=	skype.sh
SUB_LIST+=	SKYPEDIR=${SKYPEDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIDEO}
RUN_DEPENDS+=	webcamd:multimedia/webcamd
USE_LINUX+=	libv4l
SUB_LIST+=	VIDEO="LD_PRELOAD=/usr/lib/libv4l/v4l2convert.so "
.else
SUB_LIST+=	VIDEO=""
.endif

do-install:
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/skype.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png ${STAGEDIR}${PREFIX}/share/pixmaps/skype.png
	@cd ${WRKSRC}/ && ${MKDIR} ${STAGEDIR}${PREFIX}/${SKYPEDIR} && ${COPYTREE_SHARE} "avatars icons sounds lang" ${STAGEDIR}${PREFIX}/${SKYPEDIR}/

# The binary main program
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${STAGEDIR}${PREFIX}/${SKYPEDIR}/

# The wrapper for main program
	@${INSTALL_SCRIPT} ${WRKDIR}/skype.sh ${STAGEDIR}${PREFIX}/bin/skype
	@${CHMOD} a+rx ${STAGEDIR}${PREFIX}/bin/skype

.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
