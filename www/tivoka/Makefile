# Created by: gahr
# $FreeBSD$

PORTNAME=	tivoka
PORTVERSION=	3.4.2
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JSON-RPC client/server library for PHP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

OPTIONS_DEFINE=	EXAMPLES

USE_PHP=	json filter
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marcelklehr

LIBDIR=		${PREFIX}/lib/php/${PHP_EXT_DIR}/${PORTNAME}
PLIST_SUB+=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

PORTEXAMPLES=	*

do-install:
	@${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/include.php ${STAGEDIR}${LIBDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${LIBDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
