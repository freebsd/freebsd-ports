PORTNAME=	laminas-escaper
DISTVERSION=	2.18.0
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Context-specific escaping for HTML, JavaScript, CSS, and URLs
WWW=		https://docs.laminas.dev/laminas-escaper/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	laminas
USE_PHP=	ctype mbstring
IGNORE_WITH_PHP=	86

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pear/Laminas/Escaper
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/pear/Laminas/Escaper)

.include <bsd.port.mk>
