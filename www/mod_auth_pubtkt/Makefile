PORTNAME=	mod_auth_pubtkt
PORTVERSION=	0.13
CATEGORIES=	www
MASTER_SITES=	https://neon1.net/mod_auth_pubtkt/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	mk@neon1.net
COMMENT=	Apache module to provide public key ticket based authentication
WWW=		https://neon1.net/mod_auth_pubtkt/

USES=		apache
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	src/mod_auth_pubtkt.c

AP_EXTRAS=	-DAPACHE24

.include <bsd.port.mk>
