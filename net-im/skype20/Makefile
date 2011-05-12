# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# Maintainers:		Ion-Mihai Tetcu <itetcu@FreeBSD.org>
#			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	2.0.0.72
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	# the distfile is not available from vendor anymore
DISTNAME=	skype_static-${DISTVERSION}-oss

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	P2P VoIP software

LATEST_LINK=	skype20

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
USE_LINUX_APPS+=xorglibs
.else
USE_LINUX_APPS+=dri
.endif

DEPRECATED=	old version without many of the newer features; please try net-im/skype instead
EXPIRATION_DATE=2011-12-01

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

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	is the last version of skype that has OSS support, but the distfile is no longer available from the vendor, and won't be in the future. If you have a copy of
.endif

pre-fetch:
.if ${OSVERSION} < 800076
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"* * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	@${ECHO_MSG}	"ATTENTION!"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Skype requires at least linux_base-fc10"
	@${ECHO_MSG}	"which is NOT default on your system."
	@${ECHO_MSG}	"If you don't have that version or above installed,"
	@${ECHO_MSG}	"hit 'control c' now!, install it and come back."
	@${ECHO_MSG}	"* * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	@${ECHO_MSG}	""
	@sleep 10
.endif

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
