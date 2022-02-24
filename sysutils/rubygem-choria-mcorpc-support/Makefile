PORTNAME=	choria-mcorpc-support
DISTVERSION=	2.26.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Ruby support for the Choria Orchestration Server

LICENSE=	APACHE20

USES=		gem
USE_RUBY=	yes

RUN_DEPENDS=	choria>=0.20.1:sysutils/choria \
		rubygem-nats-pure>=0.6<0.8.0:net/rubygem-nats-pure \
		rubygem-systemu>=2.6.4<3:devel/rubygem-systemu

NO_ARCH=	yes

PLIST_FILES=	bin/mco

.include <bsd.port.mk>
