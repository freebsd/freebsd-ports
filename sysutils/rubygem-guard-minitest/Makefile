PORTNAME=	guard-minitest
PORTVERSION=	2.4.6
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically run your tests with Minitest framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-guard-compat>=1.2<2:sysutils/rubygem-guard-compat \
		rubygem-minitest>=3.0:devel/rubygem-minitest

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
