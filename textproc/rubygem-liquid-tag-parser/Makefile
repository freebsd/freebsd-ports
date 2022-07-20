PORTNAME=	liquid-tag-parser
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse liquid tags easily

LICENSE=	MIT

RUN_DEPENDS=	rubygem-extras>=0.3<1:devel/rubygem-extras \
		rubygem-liquid4>=3.0<5.0:textproc/rubygem-liquid4

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# Disable rdoc
OPTIONS_EXCLUDE=DOCS

.include <bsd.port.mk>
