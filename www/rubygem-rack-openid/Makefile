# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rack-openid
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a more HTTPish API around the ruby-openid library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rack>=1.1.0:${PORTSDIR}/www/rubygem-rack \
		rubygem-ruby-openid>=2.1.8:${PORTSDIR}/net/rubygem-ruby-openid

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
