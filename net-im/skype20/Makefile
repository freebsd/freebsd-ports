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
PORTVERSION=	1.4.0.118
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://download.skype.com/linux/
DISTNAME=	skype_static-${DISTVERSION}-oss

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

WRKSRC=		${WRKDIR}/skype_static-${DISTVERSION}-oss
PORTDOCS=	LICENSE README
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png ${PREFIX}/share/pixmaps/skype.png
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/bin/skype
	@${CHMOD} a+rx ${PREFIX}/bin/skype
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "avatars icons sounds lang" ${DATADIR}/

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
