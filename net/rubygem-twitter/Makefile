PORTNAME=	twitter
PORTVERSION=	8.3.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the Twitter API
WWW=		https://sferik.github.io/twitter/ \
		https://github.com/sferik/twitter-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base64>=0.3.0<0.4:converters/rubygem-base64 \
		rubygem-buftok>=1.0<2:devel/rubygem-buftok \
		rubygem-equalizer>=1.0<2:devel/rubygem-equalizer \
		rubygem-http>=6.0<7:www/rubygem-http \
		rubygem-memoizable>=0.5.1<0.6:devel/rubygem-memoizable \
		rubygem-naught>=2.3<3:devel/rubygem-naught \
		rubygem-simple_oauth>=0.4.0<0.5:net/rubygem-simple_oauth \
		rubygem-uri>=1.1<2:net/rubygem-uri

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
