# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.4 1995/04/11 23:29:45 asami Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.4
CATEGORIES+=	news
MASTER_SITES=	ftp://nic.sura.net/pub/news/software/nntp/

.if !exists(${PREFIX}/include/dbz.h) || !exists(${PREFIX}/lib/libcnews.a)
DEPENDS+=	${PORTSDIR}/news/cnews
.endif

pre-patch:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
