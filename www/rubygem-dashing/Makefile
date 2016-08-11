# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dashing
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tj@FreeBSD.org
COMMENT=	HTML dashboard framwork based on sinatra

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sass32>=3.2.12:textproc/rubygem-sass32 \
		rubygem-coffee-script>=2.3.0:devel/rubygem-coffee-script \
		rubygem-execjs>=2.2.2:devel/rubygem-execjs \
		rubygem-sinatra>=1.4.5:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=1.4.2:www/rubygem-sinatra-contrib \
		rubygem-thin>=1.6.2:www/rubygem-thin \
		rubygem-rufus-scheduler>=3.0.9:devel/rubygem-rufus-scheduler \
		rubygem-thor>=0.19.1:devel/rubygem-thor \
		rubygem-sprockets>=2.12.2:devel/rubygem-sprockets \
		rubygem-rack15>=1.5.0:www/rubygem-rack15 \
		rubygem-rake>=10.3.2:devel/rubygem-rake \
		rubygem-bundler>=1.7.3:sysutils/rubygem-bundler

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/dashing

.include <bsd.port.mk>
