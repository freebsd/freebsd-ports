PORTNAME=	sinatra
PORTVERSION=	2.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Classy web development framework in ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mustermann>=1.0<2:devel/rubygem-mustermann \
		rubygem-rack>=2.2,3<3,3:www/rubygem-rack \
		rubygem-rack-protection>=${PORTVERSION}:www/rubygem-rack-protection \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	sinatrarb

.include <bsd.port.mk>
