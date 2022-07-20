PORTNAME=	sinatra
PORTVERSION=	1.4.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Classy web development framework in ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rack16>=1.5<2:www/rubygem-rack16 \
		rubygem-rack-protection1>=1.4<2:www/rubygem-rack-protection1 \
		rubygem-tilt>=1.3<3:devel/rubygem-tilt

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	sinatrarb

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
