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

DEPRECATED=	Use www/rubygem-jekyll-watch instead
EXPIRATION_DATE=2018-01-31

RUN_DEPENDS=	rubygem-listen>=3.0:devel/rubygem-listen

PORTSCOUT=	limit:^1\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
