# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	rest-client
PORTVERSION=	2.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Simple Simple HTTP and REST client for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-http-cookie>=1.0.2:www/rubygem-http-cookie \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-netrc>=0.8:net/rubygem-netrc

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/restclient

.include <bsd.port.mk>
