# $FreeBSD$

PORTNAME=	sinatra-contrib
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Collection of useful Sinatra extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-backports>=2.0:${PORTSDIR}/devel/rubygem-backports \
		rubygem-multi_json>=0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rack-protection>=0:${PORTSDIR}/www/rubygem-rack-protection \
		rubygem-rack-test>=0:${PORTSDIR}/www/rubygem-rack-test \
		rubygem-sinatra>=1.4:${PORTSDIR}/www/rubygem-sinatra \
		rubygem-tilt1>=1.3:${PORTSDIR}/devel/rubygem-tilt1

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
