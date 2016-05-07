# $FreeBSD$

PORTNAME=	pdf-writer
PORTVERSION=	1.1.8
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure Ruby PDF document creation library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-color>=1.4.0:print/rubygem-color \
		rubygem-transaction-simple>=1.3:devel/rubygem-transaction-simple

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/techbook

.include <bsd.port.mk>
