# Created by: Maciek Korzen <eaquer@ceti.pl>
# $FreeBSD$

PORTNAME=	trf
PORTVERSION=	0.4
CATEGORIES=	polish finance
MASTER_SITES=	http://korzen.org/soft/trf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Billing software for traffic counting working with most Polish ISPs

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
