# New ports collection makefile for:    freenx
# Date created:                         Sat 11 Sep 2004
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	freenx
PORTVERSION=	0.6.0
CATEGORIES=	net
MASTER_SITES=	BERLIOS

MAINTAINER=	freenx@deweyonline.com
COMMENT=	Frontend (auth/session management) for nxserver libraries

RUN_DEPENDS=	${NXPREFIX}/bin/nxagent:${PORTSDIR}/net/nxserver \
		bash:${PORTSDIR}/shells/bash \
		expect:${PORTSDIR}/lang/expect \
		gls:${PORTSDIR}/sysutils/coreutils \
		xauth:${X_CLIENTS_PORT}
USE_PERL5_RUN=	yes

BUILD_WRKSRC=	${WRKSRC}/nxserver-helper

NXPREFIX?=	${PREFIX}/NX

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503102
RUN_DEPENDS+=	nc:${PORTSDIR}/net/netcat
.endif

.if ${OSVERSION} < 601101
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-freenx-nxserver \
	${PATCHDIR}/extra-patch-freenx-nxsetup
.endif

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e "s|/usr/local/|${PREFIX}/|" \
		-e "s|!/bin/bash|!${PREFIX}/bin/bash|" \
		-e "s|/usr/bin/expect|${PREFIX}/bin/expect|" \
		-e "s|/usr/NX|${NXPREFIX}|" \
		node.conf.sample nxclient nxkeygen nxloadconfig nxnode \
		nxnode-login nxprint nxserver nxsetup

do-install:
	${MKDIR} ${NXPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nxserver-helper/nxserver-helper \
		${NXPREFIX}/bin
.for i in nxnode nxserver nxsetup nxkeygen nxnode-login nxloadconfig nxprint nxclient
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${NXPREFIX}/bin
.endfor
	${MKDIR} ${NXPREFIX}/etc/nxserver
	${INSTALL_SCRIPT} ${WRKSRC}/node.conf.sample ${NXPREFIX}/etc/nxserver

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
