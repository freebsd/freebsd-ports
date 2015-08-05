# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	bundler
PORTVERSION=	1.7.15
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	17

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for ruby applications

LICENSE=	MIT

DEPRECATED=	not used by other ports anymore
EXPIRATION_DATE=	2015-08-12

PORTSCOUT=	limit:^1\.7\.[0-9]*

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/bundle*

.include <bsd.port.mk>
