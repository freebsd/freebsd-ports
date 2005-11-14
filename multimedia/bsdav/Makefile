# New ports collection makefile for:   bsdav
# Date created:        2005-11-04
# Whom:                Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	bsdav
PORTVERSION=	1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.jakemsr.com/bsdav/ \
	http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	BSD native set of programs for audio and video reading and writing

BROKEN=		Does not compile

INSTALLS_SHLIB=	yes

MAN1=	audiorec.1 bktrrec.1 bsdavdemux.1 bsdavrec.1 btv.1 tunerctl.1 avplay.1 \
	bktrplay.1 bsdavplay.1
MAN5=	bsdav.5

.if !( defined(NO_PORTDOCS) || defined(NOPORTDOCS) )
PORTDOCS=	README
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
