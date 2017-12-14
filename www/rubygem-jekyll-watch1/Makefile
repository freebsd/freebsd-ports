# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	jekyll-watch
PORTVERSION=	1.5.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handles rebuilding of Jekyll sites when a file changes

LICENSE=	MIT

RUN_DEPENDS=	rubygem-listen>=3.0:devel/rubygem-listen

PORTSCOUT=	limit:^1\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
