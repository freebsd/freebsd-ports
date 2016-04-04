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

RUN_DEPENDS=	lame:audio/lame \
		normalize:audio/normalize \
		oggenc:audio/vorbis-tools \
		mencoder:multimedia/mencoder \
		mkvmerge:multimedia/mkvtoolnix \
		dvdxchap:multimedia/ogmtools \
		bash:shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|normalize-audio|normalize| ; \
		 s|stat -c %s|stat -f %z|' ${WRKSRC}/iso2mkv

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/iso2mkv ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README.utf8.txt ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/iso2mkv.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
