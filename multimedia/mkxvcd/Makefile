# New ports collection makefile for:	mkxvcd
# Date created:				Fri Mar  5 04:25:02 EST 2004
# Whom:					michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	mkxvcd
PORTVERSION=	2.0.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kvcd4nix

MAINTAINER=	ahze@ahze.net
COMMENT=	Makes high quality X/K/S/VCD movies from many formats

RUN_DEPENDS=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		bash:${PORTSDIR}/shells/bash2 \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		transcode:${PORTSDIR}/multimedia/transcode

USE_REINPLACE=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/mkxvcd

DOC_FILES=	AUTHORS COPYING Changelog INSTALL README TODO

.include <bsd.port.pre.mk>

.ifndef(PORTDOCS)
.for plistfile in ${DOC_FILES}
PLIST_FILES+=	share/doc/${PORTNAME}/${plistfile}
.endfor
PLIST_DIRS+=	share/doc/${PORTNAME}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/mkxvcd.sh

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/mkxvcd.sh ${PREFIX}/bin/mkxvcd
.ifndef(PORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
