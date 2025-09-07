PORTNAME=	ruby-openai
PORTVERSION=	8.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenAI API for Ruby
WWW=		https://github.com/alexrudall/ruby-openai

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-event_stream_parser>=0.3.0<2.0.0:devel/rubygem-event_stream_parser \
		rubygem-faraday>=1:www/rubygem-faraday \
		rubygem-faraday-multipart>=1:www/rubygem-faraday-multipart

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
