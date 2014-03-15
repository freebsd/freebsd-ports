# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-streamdev
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/953/:release \
		LOCAL:snapshot
MASTER_SITE_SUBDIR=	nox/:snapshot
DISTFILES=	${DISTNAME:S/plugin-//}${EXTRACT_SUFX}:release

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - stream device plugin

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

USES=		tar:tgz
PORTDOCS=	COPYING README HISTORY
HAVE_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}
VDR_PLUGIN_MAKEFILES=	${WRKSRC}/client/Makefile \
		${WRKSRC}/server/Makefile

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${LN} -s ../locale ${WRKSRC}
	@${REINPLACE_CMD} '1s-^#!/bin/sh-#!${LOCALBASE}/bin/bash-' \
		${WRKSRC}/${PLUGIN}-server/externremux.sh

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}-server
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}-server/externremux.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/externremux.sh.sample
	@${INSTALL_DATA} ${WRKSRC}/${PLUGIN}-server/streamdevhosts.conf \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/streamdevhosts.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
