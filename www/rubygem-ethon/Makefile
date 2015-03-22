# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ethon
PORTVERSION=	0.7.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Very lightweight libcurl wrapper

LICENSE=	MIT

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	rubygem-ffi>=1.3.0:${PORTSDIR}/devel/rubygem-ffi \
		rubygem-mime-types1>=1.18:${PORTSDIR}/misc/rubygem-mime-types1

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
