# New ports collection makefile for:	nn
# Version required:	6.5.0
# Date created:		24 September 1994
# Whom:			adam
#
# $Id$
#

DISTNAME=	nn-6.5.0.b3
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/beta/

pre-configure:
	@cp ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	@cp ${WRKSRC}/conf/s-386bsd.h ${WRKSRC}/conf/s-freebsd.h

install: all
	@cd ${WRKSRC}; ./inst s

.include <bsd.port.mk>
