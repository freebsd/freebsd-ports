# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.3 1995/04/01 12:49:11 jkh Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.4
CATEGORIES+=	news
MASTER_SITES=	ftp://nic.sura.net/pub/news/software/nntp/

pre-patch:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
