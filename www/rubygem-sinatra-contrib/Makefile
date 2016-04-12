# $FreeBSD$

PORTNAME=	sinatra-contrib
PORTVERSION=	1.4.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Collection of useful Sinatra extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-backports>=2.0:devel/rubygem-backports \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-rack-protection>=0:www/rubygem-rack-protection \
		rubygem-rack-test>=0:www/rubygem-rack-test \
		rubygem-sinatra>=1.4:www/rubygem-sinatra \
		rubygem-tilt>=2.0:devel/rubygem-tilt

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
