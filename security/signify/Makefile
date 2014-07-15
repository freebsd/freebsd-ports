# $FreeBSD$

PORTNAME=	signify
PORTVERSION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.fefe.de/signify/
DISTNAME=	${PORTNAME}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	OpenBSD signify ported by fefe

LICENSE=	BSD2CLAUSE

USES=		gmake

do-install:
	${CP} ${WRKSRC}/signify ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
