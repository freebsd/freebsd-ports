PORTNAME=	typhoeus
PORTVERSION=	1.4.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	14

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parallel HTTP request library
WWW=		https://github.com/typhoeus/typhoeus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ethon>=0.9.0:www/rubygem-ethon

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.4\.

.include <bsd.port.mk>
