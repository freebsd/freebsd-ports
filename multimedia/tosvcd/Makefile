# ex:ts=8
# Ports collection makefile for:	tosvcd
# Date created:			Oct 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tosvcd
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://muse.seh.de/tosvcd/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPNDS=	mpeg2enc:${PORTSDIR}/graphics/mjpegtools \
		vcdimager:${PORTSDIR}/graphics/vcdimager

USE_BZIP2=	yes
USE_REINPLACE=	yes
MAKEFILE=	makefile
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS =|CFLAGS+=|" \
		-e "s|^CFLAGS +=|#CFLAGS +=|g" \
		-e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|" ${WRKSRC}/decode.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tosvcd ${PREFIX}/bin

.include <bsd.port.mk>
