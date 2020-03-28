# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liquid-tag-parser
PORTVERSION=	1.9.0
PORTREVISION=	3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse liquid tags easily

LICENSE=	MIT

RUN_DEPENDS=	rubygem-extras>=0.3<1:devel/rubygem-extras \
		rubygem-liquid>=3.0<5.0:textproc/rubygem-liquid

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.

# Disable rdoc
OPTIONS_EXCLUDE=DOCS

.include <bsd.port.mk>
