# New ports collection makefile for:	mpeg2codec
# Version required:	1.1a
# Date created:		June 21, 1996
# Whom:			"Philippe Charnier" <charnier@lirmm.fr>
#
# $Id$
#

DISTNAME=	mpeg2codec-1.1a
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.netcom.com/pub/cf/cfogg/mpeg2/
DISTFILES=	mpeg2codec_v1.1a.tar.gz

MAINTAINER=	charnier@lirmm.fr

USE_X11=	yes
WRKSRC=		${WRKDIR}/mpeg2

do-install:
.for i in dec enc
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/src/mpeg2${i}/mpeg2${i}ode ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
