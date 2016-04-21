# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	nusoap
PORTVERSION=	0.9.5
CATEGORIES=	net www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SOAP Toolkit for PHP

BROKEN_powerpc64=	Does not build

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
