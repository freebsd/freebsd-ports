PORTNAME=	sinatra
PORTVERSION=	4.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Classy web development framework in ruby
WWW=		https://sinatrarb.com/ \
		https://github.com/sinatra/sinatra

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-logger>=1.6.0:devel/rubygem-logger \
		rubygem-mustermann>=3.0<4:devel/rubygem-mustermann \
		rubygem-rack>=3.0.0,3<4,3:www/rubygem-rack \
		rubygem-rack-protection>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-rack-protection \
		rubygem-rack-session>=2.0.0<3:www/rubygem-rack-session \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	sinatrarb

.include <bsd.port.mk>
