# New ports collection makefile for:    freenx
# Date created:                         Sat 11 Sep 2004
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	freenx
PORTVERSION=	0.4.1
PORTREVISION=	1
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
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxclient ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxnode ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxnode-login ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxserver ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxsetup ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxkeygen ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxloadconfig ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/nxprint ${NXPREFIX}/bin
	${MKDIR} ${NXPREFIX}/etc/nxserver
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.4.1/node.conf.sample ${NXPREFIX}/etc/nxserver

.include <bsd.port.mk>
