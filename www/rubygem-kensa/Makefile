# $FreeBSD$

PORTNAME=	kensa
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Heroku Add-On provider tool

LICENSE=	MIT

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/kensa

RUN_DEPENDS+=	rubygem-launchy22>=0:devel/rubygem-launchy22 \
		rubygem-mechanize26>=0:www/rubygem-mechanize26 \
		rubygem-rest-client>=0:www/rubygem-rest-client \
		rubygem-term-ansicolor>=0:devel/rubygem-term-ansicolor \
		rubygem-sinatra>=1.4.2:www/rubygem-sinatra \
		rubygem-foreman>=0.63:devel/rubygem-foreman \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-thin>=0:www/rubygem-thin \
		rubygem-tilt1>=1.4.1:devel/rubygem-tilt1 \
		rubygem-haml>=4.0.5:www/rubygem-haml \
		rubygem-heroku-nav>=0.2.2:www/rubygem-heroku-nav \
		rubygem-json>=1.8.1:devel/rubygem-json


.include <bsd.port.mk>
