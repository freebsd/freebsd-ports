# $FreeBSD$

PORTNAME=	rouge
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, easy-to-extend drop-in replacement for pygments

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rougify

.include <bsd.port.mk>
