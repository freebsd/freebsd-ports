# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ethon
PORTVERSION=	0.5.12
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Very lightweight libcurl wrapper

RUN_DEPENDS=	rubygem-ffi>=1.3.0:${PORTSDIR}/devel/rubygem-ffi \
		rubygem-mime-types>=1.18:${PORTSDIR}/misc/rubygem-mime-types
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
