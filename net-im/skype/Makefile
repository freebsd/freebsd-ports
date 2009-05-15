# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# Maintainers:		Beech Rintoul <beech@FreeBSD.org>
#			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	2.0.0.72
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
DISTNAME=	skype_static-${DISTVERSION}-oss

MAINTAINER=	beech@FreeBSD.org
COMMENT=	P2P VoIP software

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
USE_LINUX_APPS+=xorglibs
.else
USE_LINUX_APPS+=dri
.endif

USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS+=alsalib expat fontconfig libsigcpp20
RESTRICTED=	Redistribution prohibited.

WRKSRC=		${WRKDIR}/${PORTNAME}_static-${DISTVERSION}-oss
SKYPEDIR=	share/skype
PORTDOCS=	LICENSE README
PLIST_SUB+=	SKYPEDIR=${SKYPEDIR}
SUB_FILES=	skype.sh
SUB_LIST+=	SKYPEDIR=${SKYPEDIR}

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"* * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	@${ECHO_MSG}	"ATTENTION!"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Skype requires at least linux_base-fc6"
	@${ECHO_MSG}	"which is NOT default at this time."
	@${ECHO_MSG}	"If you don't have that version or above installed,"
	@${ECHO_MSG}	"hit 'control c' now!"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Please read ${PORTSDIR}/UPDATING 20080318"
	@${ECHO_MSG}	"for update and install instructions."
	@${ECHO_MSG}	"* * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	@${ECHO_MSG}	""

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png ${PREFIX}/share/pixmaps/skype.png
	@cd ${WRKSRC}/ && ${MKDIR} ${PREFIX}/${SKYPEDIR} && ${COPYTREE_SHARE} "avatars icons sounds lang" ${PREFIX}/${SKYPEDIR}/

# The binary main program
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/${SKYPEDIR}/

# The wrapper for main program
	@${INSTALL_SCRIPT} ${WRKDIR}/skype.sh ${PREFIX}/bin/skype

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
