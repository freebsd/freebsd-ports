# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.12 1997/08/11 00:01:07 adam Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.abs.net/unix/ \
		ftp://ftp.ww.net/pub/unix/news/nntp/

MAINTAINER=	adam@veda.is

BUILD_DEPENDS=	${PREFIX}/lib/libcnews.a:${PORTSDIR}/news/cnews

BROKEN=		depends on cnews, which is broken
MAN1=		nntpxmit.1
MAN8=		nntpd.8c mkgrdates.8c

post-extract:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
