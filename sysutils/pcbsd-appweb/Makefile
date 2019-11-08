# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-appweb
PORTVERSION=	1441129621
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Web Interface

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	syscache:sysutils/pcbsd-syscache \
		pbi:sysutils/pbi-manager \
		warden:sysutils/warden \
		nginx:www/nginx

USE_PHP=	filter gd json session
WRKSRC_SUBDIR=	src-webui
USES=		php pkgconfig
NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd
GH_TAGNAME=	3c4d2b

.include <bsd.port.mk>
