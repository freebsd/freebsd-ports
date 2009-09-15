# New ports collection makefile for:	skype12
# Date created:         Jun 21. 2004
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	skype12
PORTVERSION=	1.2.0.18
CATEGORIES=	net
MASTER_SITES=	NETBSD
DISTNAME=	skype_staticQT-${PORTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Legacy version P2P VoIP software

USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	expat fontconfig
PORTDOCS=	LICENSE README
SUB_FILES=	pkg-message

RESTRICTED=	Redistribution prohibited.
CONFLICTS=	skype-1.[0-9].*

OPTIONS=	NVIDIA_GL "Enable Nvidia Support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700000
IGNORE=	Legacy version, Use net/skype
.endif

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_LINUX_APPS+=dri
.endif

WRKSRC=	${WRKDIR}/skype-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|Exec=skype|Exec=skype --resources=${PREFIX}/${SKYPEDIR}|' \
		${WRKSRC}/skype.desktop

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/skype

do-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_PROGRAM} ${WRKSRC}/skype ${PREFIX}/bin/skype
	@${CHMOD} a+rx ${PREFIX}/bin/skype
	@${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons/skype_48_32.png ${PREFIX}/share/pixmaps/skype.png
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "icons sound lang" ${DATADIR}/

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
