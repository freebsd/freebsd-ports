# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.6 1995/10/10 07:28:10 asami Exp $
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.5
CATEGORIES+=	news
MASTER_SITES=	ftp://nic.sura.net/pub/news/software/nntp/

BUILD_DEPENDS=	${PREFIX}/libexec/news/ctime:${PORTSDIR}/news/cnews

pre-patch:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
