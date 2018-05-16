# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smashing
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sinatra-based framework for building dashboards

LICENSE=	MIT

RUN_DEPENDS=	rubygem-coffee-script>=2.4.1:devel/rubygem-coffee-script \
		rubygem-execjs>=2.7.0:devel/rubygem-execjs \
		rubygem-rack>=2.0.0:www/rubygem-rack \
		rubygem-rufus-scheduler>=3.4.2:devel/rubygem-rufus-scheduler \
		rubygem-sass34>=3.4.24:textproc/rubygem-sass34 \
		rubygem-sinatra>=2.0.0:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=2.0.0:www/rubygem-sinatra-contrib \
		rubygem-sprockets3>=3.7.1:devel/rubygem-sprockets3 \
		rubygem-thin>=1.7.0:www/rubygem-thin \
		rubygem-thor>=0.19.4:devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/smashing

.include <bsd.port.mk>
