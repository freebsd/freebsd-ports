PORTNAME=	phpsysinfo
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.4
CATEGORIES=	www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

PATCH_SITES=	https://github.com/phpsysinfo/phpsysinfo/commit/
PATCHFILES=	11a18f6a50482ac38c70639c913bd1cd46f7414d.diff:-p1 \
		9f8962c851b39a1d1b0d771a0c8cb7d447639a4f.diff:-p1
 
MAINTAINER=	tremere@cainites.net
COMMENT=	PHP script for displaying system information
WWW=		https://phpsysinfo.github.io/phpsysinfo/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe php:web
USE_GITHUB=	yes
USE_PHP=	dom mbstring simplexml xml xsl

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	"@sample ${WWWDIR}/phpsysinfo.ini.new ${WWWDIR}/phpsysinfo.ini"

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! -name .travis.yml ! -name .gitignore")
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' > ${TMPPLIST}

.include <bsd.port.mk>
