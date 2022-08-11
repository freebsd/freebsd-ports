PORTNAME=	guard-rspec
PORTVERSION=	4.7.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Guard::RSpec automatically run your specs (much like autotest)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-guard>=2.1<3:sysutils/rubygem-guard \
		rubygem-guard-compat>=1.1<2:sysutils/rubygem-guard-compat \
		rubygem-rspec>=2.99.0<4.0:devel/rubygem-rspec

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
