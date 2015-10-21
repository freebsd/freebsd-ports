# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lita-gems
PORTVERSION=	1.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Lita handler for rubygems.org querying

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gems>=0.8.0:${PORTSDIR}/devel/rubygem-gems \
		rubygem-lita>=2.6:${PORTSDIR}/net-im/rubygem-lita

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
