# New ports collection makefile for:	skype-devel
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	1.4.0.118
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	LOCAL/beech
PKGNAMESUFFIX=	-devel
DISTNAME=	skype_static_staticQT-${DISTVERSION}-oss-generic

MAINTAINER=	beech@FreeBSD.org
COMMENT=	P2P VoIP software

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat \
		${LINUXBASE}/usr/lib/libsigc-2.0.so.0:${PORTSDIR}/devel/linux-libsigc++20

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_GL=	linux
.endif

USE_BZIP2=	yes
USE_LINUX=	yes

RESTRICTED=	Redistribution prohibited.

WRKSRC=		${WRKDIR}/${PORTNAME}_static-${DISTVERSION}-oss
PORTDOCS=	LICENSE README
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|Exec=skype|Exec=skype_devel --resources=${DATADIR}|' \
		${WRKSRC}/skype.desktop

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png ${PREFIX}/share/pixmaps/skype.png
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/bin/skype_devel
	@${CHMOD} a+rx ${PREFIX}/bin/skype_devel
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "avatars icons sounds lang" ${DATADIR}/

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
