# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actioncable
PORTVERSION=	6.0.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integrated WebSockets for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}:www/rubygem-actionpack60 \
		rubygem-nio4r>=2.0<3:devel/rubygem-nio4r \
		rubygem-websocket-driver>=0.6.1:www/rubygem-websocket-driver

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
