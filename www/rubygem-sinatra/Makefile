PORTNAME=	sinatra
PORTVERSION=	3.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Classy web development framework in ruby
WWW=		http://www.sinatrarb.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mustermann>=3.0<4:devel/rubygem-mustermann \
		rubygem-rack22>=2.2.4,3<3,3:www/rubygem-rack22 \
		rubygem-rack-protection>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-rack-protection \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	sinatrarb

.include <bsd.port.mk>
