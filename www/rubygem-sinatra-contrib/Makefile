# $FreeBSD$

PORTNAME=	sinatra-contrib
PORTVERSION=	2.0.0
PORTREVISION=	0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Collection of useful Sinatra extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-backports>=2.0:devel/rubygem-backports \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-rack-protection>=0:www/rubygem-rack-protection \
		rubygem-rack-test>=0:www/rubygem-rack-test \
		rubygem-sinatra>=2.0:www/rubygem-sinatra \
		rubygem-tilt>=2.0:devel/rubygem-tilt

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
