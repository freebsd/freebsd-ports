# New ports collection makefile for:	vdr-plugin-streamdev
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-streamdev
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/953/:release \
		LOCAL:snapshot
MASTER_SITE_SUBDIR=	nox/:snapshot
DISTFILES=	${DISTNAME:S/plugin-//}${EXTRACT_SUFX}:release
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - stream device plugin

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

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

post-install: post-install-pluginlocales
	@${MKDIR} ${PREFIX}/etc/vdr/plugins/${PLUGIN}-server
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}-server/externremux.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/externremux.sh.sample
	@${INSTALL_DATA} ${WRKSRC}/${PLUGIN}-server/streamdevhosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/streamdevhosts.conf.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/externremux.sh ]; then \
	    ${INSTALL_SCRIPT} -o ${VDR_USER} -g ${VDR_GROUP} ${WRKSRC}/${PLUGIN}-server/externremux.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}-server; \
	fi
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/streamdevhosts.conf ]; then \
	    ${INSTALL_DATA} -o ${VDR_USER} -g ${VDR_GROUP} ${WRKSRC}/${PLUGIN}-server/streamdevhosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}-server; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
