# New ports collection makefile for:	nn
# Version required:	6.5.0
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.4 1995/02/26 23:16:23 ats Exp $
#

DISTNAME=	nn-6.5.0.b3
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/beta/
CATEGORIES+=	news

pre-patch:
	@cp ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	@cp ${WRKSRC}/conf/s-386bsd.h ${WRKSRC}/conf/s-freebsd.h

pre-install:
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} all )
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} install )

.include <bsd.port.mk>
