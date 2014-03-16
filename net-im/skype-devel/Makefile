# Created by: netchild@FreeBSD.org
# $FreeBSD$

PORTNAME=	skype
PORTVERSION=	2.2.0.35
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://download.skype.com/linux/
PKGNAMESUFFIX=	-devel
DISTNAME=	skype_static-${DISTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	P2P VoIP software, development version

CONFLICTS=	skype-[0-9]*

OPTIONS_DEFINE=	VIDEO NVIDIA_GL
VIDEO_DESC=[broken] Video support
NVIDIA_GL_DESC=	libGL provided by NVidia binary drivers

OPTIONS_DEFAULT=	VIDEO

CONFLICTS=	skype-1* skype-2.0* skype-2.1*

NO_BUILD=	yes

USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS+=alsalib alsa-plugins-oss expat fontconfig libasyncns \
		libsigcpp20
RESTRICTED=	Redistribution prohibited.

WRKSRC=		${WRKDIR}/${PORTNAME}_static-${DISTVERSION}
SKYPEDIR=	share/skype
PORTDOCS=	LICENSE README
PLIST_SUB+=	SKYPEDIR=${SKYPEDIR}
SUB_FILES=	skype.sh
SUB_LIST+=	SKYPEDIR=${SKYPEDIR}

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNVIDIA_GL}
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
USE_LINUX_APPS+=xorglibs
.else
USE_LINUX_APPS+=dri
.endif

.if ${PORT_OPTIONS:MVIDEO}
RUN_DEPENDS+=	webcamd>0:${PORTSDIR}/multimedia/webcamd
USE_LINUX_APPS+=libv4l
SUB_LIST+=	VIDEO="LD_PRELOAD=/usr/lib/libv4l/v4l2convert.so "
.else
SUB_LIST+=	VIDEO=""
.endif

### FIX ME, once they get bumped:
# for 7: 704102
# for 8: 802504
# for HEAD: 900037
# we need src/sys/dev/sound/pcm/dsp.c r221388
IGNORE_MSG=	needs sys/dev/sound/pcm/dsp.c r221388 (and other changes).\
		Please update your system post 
.if ${OSVERSION} < 704102
OUTDATED=	true
IGNORE_MSG+=	r221584 / Sat May 7 09:33:37 2011 UTC
.elif (${OSVERSION} > 800000 && ${OSVERSION} < 802503)
OUTDATED=	true
IGNORE_MSG+=	r221583 / Sat May 7 09:26:11 2011 UTC
.elif (${OSVERSION} > 900000 && ${OSVERSION} < 900036)
OUTDATED=	true
IGNORE_MSG+=	r221388 / Tue May 3 15:50:22 2011 UTC
.endif
.ifdef OUTDATED
IGNORE=	${IGNORE_MSG}
.endif

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png ${PREFIX}/share/pixmaps/skype.png
	@cd ${WRKSRC}/ && ${MKDIR} ${PREFIX}/${SKYPEDIR} && ${COPYTREE_SHARE} "avatars icons sounds lang" ${PREFIX}/${SKYPEDIR}/

# The binary main program
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/${SKYPEDIR}/

# The wrapper for main program
	@${INSTALL_SCRIPT} ${WRKDIR}/skype.sh ${PREFIX}/bin/skype
	@${CHMOD} a+rx ${PREFIX}/bin/skype

.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
