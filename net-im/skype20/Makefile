# New ports collection makefile for:	skype
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype
PORTVERSION=	1.4.0.118
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
ONLY_FOR_ARCHS=	i386

RESTRICTED=	Redistribution not allowed

WRKSRC=		${WRKDIR}/${PORTNAME}_static-${DISTVERSION}-oss
DATADIR=	${PREFIX}/share/${PKGBASE}

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/bin/skype
	@${CHMOD} a+rx ${PREFIX}/bin/skype
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "icons sounds lang LICENSE README" ${DATADIR}/
	@${ECHO} "There are known problems with some soundcards in 5.x. This is due to a bug in the kernel. If you experience problems update to the most recent FreeBSD RELEASE, if this does not fix your problems, ask on multimedia@FreeBSD.org." | fmt

.include <bsd.port.mk>
