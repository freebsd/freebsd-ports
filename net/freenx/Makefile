# New ports collection makefile for:    freenx
# Date created:                         Sat 11 Sep 2004
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	freenx
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/freenx/ \
		http://debian.tu-bs.de/knoppix/nx/

MAINTAINER=	freenx@deweyonline.com
COMMENT=	Frontend (auth/session management) for nxserver libraries

RUN_DEPENDS=	${NXPREFIX}/bin/nxagent:${PORTSDIR}/net/nxserver \
		bash:${PORTSDIR}/shells/bash \
		expect:${PORTSDIR}/lang/expect \
		xauth:${X_CLIENTS_PORT}

NO_BUILD=	yes

USE_X_PREFIX=	yes
NXPREFIX?=	${PREFIX}/NX
WRKSRC=		${WRKDIR}

do-install:
	${MKDIR} ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxclient ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxnode ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxnode-login ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxserver ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxsetup ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxkeygen ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxloadconfig ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/nxprint ${NXPREFIX}/bin
	${MKDIR} ${NXPREFIX}/etc/nxserver
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.4/node.conf.sample ${NXPREFIX}/etc/nxserver

.include <bsd.port.mk>
