PORTNAME=	tomlrb
PORTVERSION=	2.0.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Racc-based TOML parser
WWW=		https://github.com/fbernier/tomlrb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-racc>=1.4<2:devel/rubygem-racc

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
