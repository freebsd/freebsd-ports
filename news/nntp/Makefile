# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.7 1995/10/20 08:48:03 asami Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.5
CATEGORIES+=	news
MASTER_SITES=	ftp://nic.sura.net/pub/news/software/nntp/

BUILD_DEPENDS=	${PREFIX}/lib/libcnews.a:${PORTSDIR}/news/cnews

pre-patch:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
