# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.10 1996/11/18 11:37:53 asami Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.5
CATEGORIES=	news
MASTER_SITES=	ftp://nic.sura.net/pub/news/software/nntp/

MAINTAINER=	adam@veda.is

BUILD_DEPENDS=	${PREFIX}/lib/libcnews.a:${PORTSDIR}/news/cnews

MAN1=		nntpxmit.1
MAN8=		nntpd.8c mkgrdates.8c

post-extract:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
