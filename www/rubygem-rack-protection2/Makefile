PORTNAME=	rack-protection
PORTVERSION=	2.2.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2
PORTREVISION=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of Rack middleware to protect against opportunistic attack
WWW=		https://github.com/sinatra/sinatra/tree/master/rack-protection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License

RUN_DEPENDS=	rubygem-rack22>=0,3:www/rubygem-rack22

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
