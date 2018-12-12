# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-streamdev
PORTVERSION=	0.6.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/1580/:release \
		LOCAL/nox:snapshot
DISTFILES=	${DISTNAME:S/plugin-//}${EXTRACT_SUFX}:release

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - stream device plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix tar:tgz
SHEBANG_FILES=	streamdev-server/externremux.sh
MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}
VDR_PLUGIN_MAKEFILES=\
		${WRKSRC}/client/Makefile \
		${WRKSRC}/server/Makefile

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS NLS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

pre-patch:
	@${CP} ${WRKSRC}/Makefile-1.7.33 ${WRKSRC}/Makefile
	@${CP} ${WRKSRC}/client/Makefile-1.7.33 ${WRKSRC}/client/Makefile
	@${CP} ${WRKSRC}/server/Makefile-1.7.33 ${WRKSRC}/server/Makefile

post-patch: post-patch-plugin
	@${LN} -s ../locale ${WRKSRC}
	@${REINPLACE_CMD} '1s-^#!/bin/sh-#!${LOCALBASE}/bin/bash-' \
		${WRKSRC}/${PLUGIN}-server/externremux.sh

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}-server
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}-server/externremux.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/externremux.sh.sample
	${INSTALL_DATA} ${WRKSRC}/${PLUGIN}-server/streamdevhosts.conf \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}-server/streamdevhosts.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
