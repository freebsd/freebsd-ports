# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liquid-tag-parser
PORTVERSION=	1.9.0
PORTREVISION=	2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse liquid tags easily

LICENSE=	MIT

RUN_DEPENDS=	rubygem-extras>=0.3:devel/rubygem-extras \
		rubygem-liquid>=3.0:textproc/rubygem-liquid

NO_ARCH=	yes
USES=		compiler:c++11-lang gem
USE_RUBY=	yes

# Disable rdoc
OPTIONS_EXCLUDE=DOCS

.include <bsd.port.mk>
