PORTNAME=	rouge
PORTVERSION=	4.1.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, easy-to-extend drop-in replacement for pygments
WWW=		https://github.com/jneen/rouge

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.1\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rougify

.include <bsd.port.mk>
