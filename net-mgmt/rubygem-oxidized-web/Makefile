# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	oxidized-web
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	nick@foobar.org
COMMENT=	Web user interface and RESTful API for rubygems-oxidized

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-emk-sinatra-url-for>=0.2:www/rubygem-emk-sinatra-url-for \
		rubygem-haml4>=4.0:www/rubygem-haml4 \
		rubygem-oxidized>=0.13:net-mgmt/rubygem-oxidized \
		rubygem-puma2>=2.8:www/rubygem-puma2 \
		rubygem-sass>=3.3:textproc/rubygem-sass \
		rubygem-sinatra-contrib>=1.4:www/rubygem-sinatra-contrib \
		rubygem-sinatra1>=1.4:www/rubygem-sinatra1

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
