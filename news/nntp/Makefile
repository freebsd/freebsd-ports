# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.2 1994/11/26 17:32:34 adam Exp $
#

DISTNAME=	nntp-t5
MASTER_SITES=	ftp://nic.sura.net/pub/news/software/nntp/
CATEGORIES+=	news
#DO_NADA=	echo ${.TARGET}:
#DEPENDS=	news/cnews

pre-patch:
	@cp ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

.include <bsd.port.mk>
