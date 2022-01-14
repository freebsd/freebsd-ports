# Created by: Jin-Sih Lin <linpct@gmail.com>

PORTNAME=	phalcon
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0beta2
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	franco@opnsense.org
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/psr.so:devel/pecl-psr@${PHP_FLAVOR}

USES=		localbase php:ext
USE_GITHUB=	yes
GH_PROJECT=	c${PORTNAME}
USE_PHP=	json:build pdo:build session:build
IGNORE_WITH_PHP=	73 81

CONFIGURE_ARGS=	--enable-phalcon

CONFLICTS_INSTALL=	${PKGNAMEPREFIX}phalcon4

WRKSRC_SUBDIR=	build/phalcon

.include <bsd.port.mk>
