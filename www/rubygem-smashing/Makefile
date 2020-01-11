# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smashing
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sinatra-based framework for building dashboards

LICENSE=	MIT

RUN_DEPENDS=	rubygem-coffee-script>=2.4.1<2.5:devel/rubygem-coffee-script \
		rubygem-execjs>=2.7.0<2.8:devel/rubygem-execjs \
		rubygem-rack20>=2.0.0,3<2.1,3:www/rubygem-rack20 \
		rubygem-rufus-scheduler>=3.4.2<4:devel/rubygem-rufus-scheduler \
		rubygem-sass34>=3.4.24<3.5:textproc/rubygem-sass34 \
		rubygem-sinatra>=2.0.0<2.1:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=2.0.0<2.1:www/rubygem-sinatra-contrib \
		rubygem-sprockets3>=3.7.1<3.8:devel/rubygem-sprockets3 \
		rubygem-thin>=1.7.0<1.8:www/rubygem-thin \
		rubygem-thor>=0.19.4<1:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/smashing

.include <bsd.port.mk>
