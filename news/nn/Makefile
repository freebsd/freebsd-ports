# New ports collection makefile for:	nn
# Version required:	6.5.0
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.2 1994/11/10 17:28:47 ache Exp $
#

DISTNAME=	nn-6.5.0.b3
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/beta/

pre-patch:
	@cp ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	@cp ${WRKSRC}/conf/s-386bsd.h ${WRKSRC}/conf/s-freebsd.h

pre-build:
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} all )

pre-install:
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} install )

.include <bsd.port.mk>
