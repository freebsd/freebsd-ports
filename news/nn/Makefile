# New ports collection makefile for:	nn
# Version required:	6.5.0
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.5 1995/04/01 12:49:10 jkh Exp $
#

DISTNAME=	nn-6.5.0.b3
PKGNAME=	nn-6.5.0
CATEGORIES+=	news
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/beta/

pre-patch:
	@cp ${WRKSRC}/config.h-dist ${WRKSRC}/config.h
	@cp ${WRKSRC}/conf/s-386bsd.h ${WRKSRC}/conf/s-freebsd.h

pre-install:
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} all )
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} install )

.include <bsd.port.mk>
