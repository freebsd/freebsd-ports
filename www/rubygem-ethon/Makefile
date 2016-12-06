# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ethon
PORTVERSION=	0.10.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Very lightweight libcurl wrapper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	rubygem-ffi>=1.3.0:devel/rubygem-ffi

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
