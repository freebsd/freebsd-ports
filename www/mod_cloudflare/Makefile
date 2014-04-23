# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_cloudflare
PORTVERSION=	0.0.20140409
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Cloudflare fork of mod_remoteip

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_PROJECT=	mod_cloudflare
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	da8436d

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	cloudflare

SRC_FILE=	mod_cloudflare.c

.include <bsd.port.mk>
