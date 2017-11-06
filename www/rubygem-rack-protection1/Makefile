# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rack-protection
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of Rack middleware to protect against opportunistic attack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License

RUN_DEPENDS=	rubygem-rack>=0:www/rubygem-rack

PORTSCOUT=	limit:^1\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
