# $FreeBSD$

PORTNAME=	webmock
PORTVERSION=	1.21.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Allows stubbing HTTP requests and setting expectations on the requests

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3.6:${PORTSDIR}/www/rubygem-addressable \
		rubygem-crack>=0.3.2:${PORTSDIR}/devel/rubygem-crack

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
