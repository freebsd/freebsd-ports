# New ports collection makefile for:	transmisson-remote-gui
# Date created:		2009-05-20
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmisson-remote-gui
PORTVERSION=	2.2
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	transgui-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus
RUN_DEPENDS=	transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon

USE_GMAKE=	yes
USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_FPC=	fcl-net

WRKSRC=		${WRKDIR}/TransGUI
PLIST_FILES=	bin/transgui
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && \
		${INSTALL_PROGRAM} transgui ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
