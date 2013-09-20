# Created by: Maciek Korzen <eaquer@ceti.pl>
# $FreeBSD$

PORTNAME=	trf
PORTVERSION=	0.4
CATEGORIES=	polish finance
MASTER_SITES=	http://korzen.org/soft/trf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Billing software for traffic counting working with most Polish ISPs

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
