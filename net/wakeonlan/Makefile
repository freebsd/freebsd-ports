# New ports collection makefile for:	wakeonlan
# Date created:				30 June 2001
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wakeonlan
PORTVERSION=	0.40
CATEGORIES=	net
MASTER_SITES=	http://gsd.di.uminho.pt/jpo/software/wakeonlan/downloads/

MAINTAINER=	ports@FreeBSD.org

PERL_CONFIGURE=	yes

MAN1=           wakeonlan.1

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/lab001.wol ${EXAMPLESDIR}

.include <bsd.port.mk>
