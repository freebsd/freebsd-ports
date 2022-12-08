PORTNAME=	smashing
PORTVERSION=	1.3.5
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sinatra-based framework for building dashboards
WWW=		https://smashing.github.io/

LICENSE=	MIT

RUN_DEPENDS=	rubygem-coffee-script>=2.4<3:devel/rubygem-coffee-script \
		rubygem-execjs>=2.7<3:devel/rubygem-execjs \
		rubygem-rack22>=2.2,3<3,3:www/rubygem-rack22 \
		rubygem-rufus-scheduler>=3.6<4:devel/rubygem-rufus-scheduler \
		rubygem-sassc>=2.0<3:textproc/rubygem-sassc \
		rubygem-sinatra2>=2.0<3:www/rubygem-sinatra2 \
		rubygem-sinatra-contrib2>=2.0<3:www/rubygem-sinatra-contrib2 \
		rubygem-sprockets>=4.0<5:devel/rubygem-sprockets \
		rubygem-thin>=1.7<2:www/rubygem-thin \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/smashing

CPE_VENDOR=	smashing_project

.include <bsd.port.mk>
