# New ports collection makefile for:	transmisson-remote-gui
# Date created:		2009-05-20
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmisson-remote-gui
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	transgui-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus
RUN_DEPENDS=	transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_FPC=	fcl-net

WRKSRC=		${WRKDIR}/TransGUI
PLIST_FILES=	bin/transgui
SUB_FILES=	pkg-message

LAZARUS_PROJECT_FILE=	transgui.lpi
LAZBUILD_CMD=		${LOCALBASE}/bin/lazbuild

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/lazbuild)
LCL_PLATFORM!=		${SED} -e 1d -e 's/^LCL_PLATFORM=\(.*\).*$$/\1/' ${LOCALBASE}/etc/lazbuild.cfg
.endif

do-build:
	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} ${LAZARUS_PROJECT_FILE}

do-install:
	@cd ${WRKSRC} && \
		${INSTALL_PROGRAM} units/transgui ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
