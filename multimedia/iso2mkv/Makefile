# Created by: Alexander Botero-Lowry <alexbl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iso2mkv
DISTVERSION=	2011-05-02
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://5ko.free.fr/dl/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script to convert DVD image, device, or VIDEO_TS to mkv

LICENSE=	MIT

RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		normalize:${PORTSDIR}/audio/normalize \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix \
		dvdxchap:${PORTSDIR}/multimedia/ogmtools \
		bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

USES=		tar:bzip2

OPTIONS_DEFINE=		DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|normalize-audio|normalize| ; \
		 s|stat -c %s|stat -f %z|' ${WRKSRC}/iso2mkv

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/iso2mkv ${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README.utf8.txt ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/iso2mkv.conf ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO} "Users should copy ${EXAMPLESDIR}/iso2mkv.conf to ~/.mplayer/iso2mkv.conf"
.endif

.include <bsd.port.mk>
