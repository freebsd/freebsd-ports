PORTNAME=	twitter
PORTVERSION=	8.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the Twitter API
WWW=		https://sferik.github.io/twitter/ \
		https://github.com/sferik/twitter-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-buftok>=0.3.0<0.4:devel/rubygem-buftok \
		rubygem-equalizer>=0.0.11<0.1:devel/rubygem-equalizer \
		rubygem-llhttp-ffi>=0.5.0<0.6:www/rubygem-llhttp-ffi \
		rubygem-http>=5.2<6:www/rubygem-http \
		rubygem-http-form_data>=2.3<3:www/rubygem-http-form_data \
		rubygem-memoizable>=0.4.0<0.5:devel/rubygem-memoizable \
		rubygem-multipart-post>=2.4<3:www/rubygem-multipart-post \
		rubygem-naught>=1.1<2:devel/rubygem-naught \
		rubygem-simple_oauth>=0.3.0<0.4:net/rubygem-simple_oauth

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
