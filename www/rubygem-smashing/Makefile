# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smashing
PORTVERSION=	1.3.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sinatra-based framework for building dashboards

LICENSE=	MIT

RUN_DEPENDS=	rubygem-coffee-script>=2.4<3:devel/rubygem-coffee-script \
		rubygem-execjs>=2.7<3:devel/rubygem-execjs \
		rubygem-rack>=2.2,3<3,3:www/rubygem-rack \
		rubygem-rufus-scheduler>=3.6<4:devel/rubygem-rufus-scheduler \
		rubygem-sassc>=2.0<3:textproc/rubygem-sassc \
		rubygem-sinatra>=2.0<3:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=2.0<3:www/rubygem-sinatra-contrib \
		rubygem-sprockets>=4.0<5:devel/rubygem-sprockets \
		rubygem-thin>=1.7<2:www/rubygem-thin \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/smashing

.include <bsd.port.mk>
