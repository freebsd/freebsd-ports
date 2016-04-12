# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guard-rspec
PORTVERSION=	4.6.5
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Guard::RSpec automatically run your specs (much like autotest)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-guard>=2.1:sysutils/rubygem-guard \
		rubygem-guard-compat>=1.1:sysutils/rubygem-guard-compat \
		rubygem-rspec>=2.99.0:devel/rubygem-rspec

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
