# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mod_memcache
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Apache 2.2.x module to manage apr_memcache connections

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		apache:2.2+
USE_GITHUB=	yes
GH_ACCOUNT=	joshrotenberg
GH_PROJECT=	modmemcache
GH_TAGNAME=	8e6d912

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	src/${PORTNAME}.c

.include <bsd.port.mk>
