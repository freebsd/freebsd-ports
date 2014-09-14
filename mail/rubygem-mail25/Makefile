# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	mail
PORTVERSION=	2.5.4
PORTEPOCH=	2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	25

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby email handler

LICENSE=	MIT

RUN_DEPENDS=	rubygem-mime-types1>=1.25.1:${PORTSDIR}/misc/rubygem-mime-types1 \
		rubygem-treetop>=1.4.8:${PORTSDIR}/devel/rubygem-treetop

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
