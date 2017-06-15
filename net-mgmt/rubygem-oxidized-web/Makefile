# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	oxidized-web
PORTVERSION=	0.7.1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	nick@foobar.org
COMMENT=	Web user interface and RESTful API for rubygems-oxidized

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-emk-sinatra-url-for>=0.2:www/rubygem-emk-sinatra-url-for \
		rubygem-haml>=4.0:www/rubygem-haml \
		rubygem-oxidized>=0.13:net-mgmt/rubygem-oxidized \
		rubygem-puma>=2.8:www/rubygem-puma \
		rubygem-sass>=3.3:textproc/rubygem-sass \
		rubygem-sinatra-contrib>=1.4:www/rubygem-sinatra-contrib \
		rubygem-sinatra>=1.4:www/rubygem-sinatra

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
