# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.13 1997/12/10 08:57:53 asami Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.abs.net/unix/ \
		ftp://ftp.ww.net/pub/unix/news/nntp/

MAINTAINER=	adam@veda.is

BUILD_DEPENDS=	${PREFIX}/lib/libcnews.a:${PORTSDIR}/news/cnews

MAN1=		nntpxmit.1
MAN8=		nntpd.8c mkgrdates.8c

post-extract:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
