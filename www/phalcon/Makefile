PORTNAME=	phalcon
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7.0
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	franco@opnsense.org
COMMENT=	Phalcon PHP Framework written in C-language
WWW=		https://phalcon.io/

LICENSE=	BSD3CLAUSE

USES=		localbase php:build,ext
USE_GITHUB=	yes
GH_PROJECT=	c${PORTNAME}
USE_PHP=	mbstring pdo:build session:build
IGNORE_WITH_PHP=	84

CONFIGURE_ARGS=	--enable-phalcon

WRKSRC_SUBDIR=	build/phalcon

.include <bsd.port.mk>
