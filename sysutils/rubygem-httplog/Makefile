# $FreeBSD$

PORTNAME=	httplog
PORTVERSION=	1.1.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Log outgoing HTTP requests

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rack>=1.0:www/rubygem-rack \
		rubygem-rainbow>=2.0.0:devel/rubygem-rainbow

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
