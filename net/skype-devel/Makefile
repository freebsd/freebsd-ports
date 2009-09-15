# New ports collection makefile for:	skype-devel
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	2.0.0.68
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
PKGNAMESUFFIX=	-devel
DISTNAME=	skype_static-${DISTVERSION}-oss

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat \
		${LINUXBASE}/usr/lib/libsigc-2.0.so.0:${PORTSDIR}/devel/linux-libsigc++20 \
		${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-alsa-lib

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_LINUX_APPS+=dri
.endif

USE_BZIP2=	yes
USE_LINUX=	yes
RESTRICTED=	Redistribution prohibited.

IGNORE=		has moved, use net/skype instead

WRKSRC=		${WRKDIR}/${PORTNAME}_static-${DISTVERSION}-oss
SKYPEDIR=	share/skype
PORTDOCS=	LICENSE README
SUB_FILES=	pkg-message
SUB_LIST=	SKYPEDIR=${SKYPEDIR}
PLIST_SUB=	SKYPEDIR=${SKYPEDIR}

.include <bsd.port.pre.mk>

post-patch:
	@${MV} ${WRKSRC}/skype.desktop ${WRKSRC}/skype-devel.desktop
	@${REINPLACE_CMD} -e 's|Exec=skype|Exec=skype_devel --resources=${PREFIX}/${SKYPEDIR}|' \
		${WRKSRC}/skype-devel.desktop

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL} ${WRKSRC}/skype-devel.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png ${PREFIX}/share/pixmaps/skype.png
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/bin/skype_devel
	@${CHMOD} a+rx ${PREFIX}/bin/skype_devel
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "avatars icons sounds lang" ${PREFIX}/${SKYPEDIR}/

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
