# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	nusoap
PORTVERSION=	0.9.5
CATEGORIES=	net www
MASTER_SITES=	SF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	SOAP Toolkit for PHP

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	curl zlib xml

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
