# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	phraze
PORTVERSION=	0.4
CATEGORIES=	misc
MASTER_SITES=	http://www.incava.org/pub/phraze/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Converts telephone number to combinations of valid words

BROKEN=		unfetchable

USE_RUBY=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/ruby|#!${RUBY}|; \
	s|/usr/share/phraze|${DATADIR}|' ${WRKSRC}/phraze ${WRKSRC}/phraze.1

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/wordlist.phr ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/phraze ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/phraze.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
