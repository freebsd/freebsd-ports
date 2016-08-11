# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	mail
PORTVERSION=	2.5.4
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	25

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby email handler

LICENSE=	MIT

RUN_DEPENDS=	rubygem-mime-types1>=1.16:misc/rubygem-mime-types1 \
		rubygem-treetop>=1.4.8:devel/rubygem-treetop

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PORTSCOUT=      limit:^2\.5

.include <bsd.port.mk>
