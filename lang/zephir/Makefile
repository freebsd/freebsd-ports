PORTNAME=	zephir
DISTVERSION=	0.16.0
CATEGORIES=	lang
MASTER_SITES=	https://github.com/zephir-lang/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.phar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	cmcdonald@netgate.com
COMMENT=	Zephir is a transpiled language used for creating C-extensions for PHP

LICENSE=	MIT

RUN_DEPENDS=	re2c>0:devel/re2c

USES=		php:cli,flavors
USE_PHP=	dom filter iconv phar xml zephir_parser zlib
IGNORE_WITH_PHP=	82

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${DISTNAME} \
		bin/${DISTNAME}${EXTRACT_SUFX}

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${PREFIX}/bin/
	${LN} -s ${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
