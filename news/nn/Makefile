# New ports collection makefile for:	nn
# Version required:	6.5.0
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.7 1995/04/15 03:11:37 ache Exp $
#

DISTNAME=	nn-6.5.0.b3
PKGNAME=	nn-6.5.0
CATEGORIES+=	news
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/beta/
MAINTAINER=     ache@FreeBSD.ORG

pre-patch:
	@cp ${WRKSRC}/config.h-dist ${WRKSRC}/config.h

pre-build:
	@cp ${.CURDIR}/files/s-freebsd.h ${WRKSRC}/conf

pre-install:
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} all )
	[ -r /usr/local/lib/news/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} install )

post-install:
	@echo Put your NNTP host into ${PREFIX}/lib/news/nntp_server file

.include <bsd.port.mk>
