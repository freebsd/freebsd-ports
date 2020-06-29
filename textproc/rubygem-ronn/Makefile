# $FreeBSD$

PORTNAME=	ronn
PORTVERSION=	0.7.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Builds manuals

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-hpricot>=0.8.2:www/rubygem-hpricot \
		rubygem-rdiscount>=1.5.8:textproc/rubygem-rdiscount \
		rubygem-mustache>=0.7.0:devel/rubygem-mustache

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/ronn

.include <bsd.port.mk>
