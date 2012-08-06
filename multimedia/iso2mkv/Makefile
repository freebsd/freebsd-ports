# New ports collection makefile for:	iso2mkv
# Date created:			31 Dec 2006
# Whom:				Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iso2mkv
DISTVERSION=	2007-04-25
CATEGORIES=	multimedia
MASTER_SITES=	http://5ko.free.fr/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script to convert DVD image, device, or VIDEO_TS to mkv

RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		normalize:${PORTSDIR}/audio/normalize \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix \
		bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USE_BZIP2=	yes

PLIST_FILES=	bin/iso2mkv
PORTDOCS=	README.utf8.txt
PORTEXAMPLES=	iso2mkv.conf

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|normalize-audio|normalize| ; \
		 s|stat -c %s|stat -f %z|' ${WRKSRC}/iso2mkv
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/iso2mkv ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif
	@${CAT} ${WRKSRC}/README.utf8.txt
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${EXAMPLESDIR}/
	@${ECHO} "${EXAMPLESDIR}/${PORTEXAMPLES} should be copied to   ~/.mplayer/iso2mkv.conf"
.endif

.include <bsd.port.mk>
