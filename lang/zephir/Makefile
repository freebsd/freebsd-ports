PORTNAME=	zephir
DISTVERSION=	0.19.0
CATEGORIES=	lang
MASTER_SITES=	https://github.com/zephir-lang/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.phar
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	rcm@rcm.sh
COMMENT=	Zephir is a transpiled language used for creating C-extensions for PHP
WWW=		https://github.com/zephir-lang/zephir

LICENSE=	MIT

RUN_DEPENDS=	re2c>0:devel/re2c

USES=		php:cli,flavors
USE_PHP=	dom ctype filter mbstring phar xml zephir_parser zlib

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${DISTNAME} \
		bin/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
