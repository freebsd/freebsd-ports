# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guard-rspec
PORTVERSION=	3.1.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Guard::RSpec automatically run your specs (much like autotest)

LICENSE=	MIT

RUN_DEPENDS=	rubygem-guard>=1.8:${PORTSDIR}/sysutils/rubygem-guard \
		rubygem-rspec>=2.13:${PORTSDIR}/devel/rubygem-rspec

NO_STAGE=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
