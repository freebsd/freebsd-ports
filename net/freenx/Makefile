# New ports collection makefile for:    freenx
# Date created:                         Sat 11 Sep 2004
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	freenx
PORTVERSION=	0.3.1
CATEGORIES=	net
MASTER_SITES=	http://debian.tu-bs.de/knoppix/nx/

MAINTAINER=	freenx@deweyonline.com
COMMENT=	Low-bandwidth X network server

RUN_DEPENDS=	${NXPREFIX}/bin/nxagent:${PORTSDIR}/net/nxserver \
		bash:${PORTSDIR}/shells/bash2 \
		expect:${PORTSDIR}/lang/expect

NO_BUILD=	yes

USE_X_PREFIX=	yes
NXPREFIX?=	${PREFIX}/NX
WRKSRC=		${WRKDIR}

do-install:
	${MKDIR} ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.3.1/nxclient ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.3.1/nxnode ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.3.1/nxnode-login ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.3.1/nxserver ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.3.1/nxsetup ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.3.1/nxkeygen ${NXPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freenx-0.3.1/nxloadconfig ${NXPREFIX}/bin

.include <bsd.port.mk>
