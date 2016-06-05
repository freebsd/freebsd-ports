# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	sprinkle
DISTVERSION=	2007-08-07
CATEGORIES=	net python
MASTER_SITES=	http://www.thuswise.org/sprinkle/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stomp messaging broker written in Python

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv3

NO_BUILD=	yes
USES=		python
WRKSRC=		${WRKDIR}/sprinkle-dist

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sprinkle.py ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
