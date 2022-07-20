PORTNAME=	stompserver
PORTVERSION=	0.9.9
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provide reliable messaging using the stomp protocol

LICENSE=	MIT

RUN_DEPENDS=	rubygem-daemons>=1.0.2:devel/rubygem-daemons \
		rubygem-eventmachine>=0.7.2:devel/rubygem-eventmachine \
		rubygem-hoe>=1.3.0:devel/rubygem-hoe

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/stompserver

.include <bsd.port.mk>
