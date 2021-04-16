PORTNAME=	choria-mcorpc-support
DISTVERSION=	2.24.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Ruby support for the Choria Orchestration Server

LICENSE=	APACHE20

USES=		gem
USE_RUBY=	yes

RUN_DEPENDS=	choria>=0.20.1:sysutils/choria \
		rubygem-nats-pure>=0.6:net/rubygem-nats-pure \
		rubygem-systemu>=2.6.4:devel/rubygem-systemu

PLIST_FILES=	bin/mco

.include <bsd.port.mk>
