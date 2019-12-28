# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dashing
PORTVERSION=	1.3.7
PORTREVISION=	3
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML dashboard framwork based on sinatra

LICENSE=	MIT

RUN_DEPENDS=	rubygem-coffee-script>=2.2.0:devel/rubygem-coffee-script \
		rubygem-execjs>=2.0.2:devel/rubygem-execjs \
		rubygem-rack15>=1.5.4,4<1.6,4:www/rubygem-rack15 \
		rubygem-rufus-scheduler>=2.0.24:devel/rubygem-rufus-scheduler \
		rubygem-sass32>=3.2.12<3.3:textproc/rubygem-sass32 \
		rubygem-sinatra1>=1.4.4<1.5:www/rubygem-sinatra1 \
		rubygem-sinatra-contrib1>=1.4.2<1.5:www/rubygem-sinatra-contrib1 \
		rubygem-sprockets2>=2.10.1:devel/rubygem-sprockets2 \
		rubygem-thin>=1.6.1:www/rubygem-thin \
		rubygem-thor>=0.18.1:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/dashing

.include <bsd.port.mk>
