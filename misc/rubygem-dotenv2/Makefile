PORTNAME=	dotenv
PORTVERSION=	2.8.1
CATEGORIES=	misc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Loads environment variables from .env
WWW=		https://github.com/bkeepers/dotenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/dotenv

.include <bsd.port.mk>
