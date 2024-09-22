PORTNAME=	mod_cloudflare
PORTVERSION=	2016.10.0
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Cloudflare fork of mod_remoteip
WWW=		https://github.com/cloudflare/mod_cloudflare

LICENSE=	APACHE20

DEPRECATED=	Deprecated upstream 20 Jul 2021, upstream recommends mod_remoteip
EXPIRATION_DATE=2024-10-31

CONFLICTS_INSTALL=	${PKGNAMEPREFIX}mod_remoteip

USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_TAGNAME=	98ab38a

USES=		apache
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	cloudflare

SRC_FILE=	mod_cloudflare.c

.include <bsd.port.mk>
