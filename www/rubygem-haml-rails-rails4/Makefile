# $FreeBSD$

PORTNAME=	haml-rails
PORTVERSION=	0.5.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Haml generator for Rails

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack4>=4.1.4:${PORTSDIR}/www/rubygem-actionpack4 \
		rubygem-activesupport4>=4.1.4:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-haml>=3.1:${PORTSDIR}/www/rubygem-haml \
		rubygem-railties4>=4.1.4:${PORTSDIR}/www/rubygem-railties4

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
