# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.9 1996/03/20 01:48:26 adam Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.5
CATEGORIES=	news
MASTER_SITES=	ftp://nic.sura.net/pub/news/software/nntp/

MAINTAINER=	adam@veda.is

BUILD_DEPENDS=	${PREFIX}/lib/libcnews.a:${PORTSDIR}/news/cnews

post-extract:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
