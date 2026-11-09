PORTNAME=	url-highlight
DISTVERSION=	4.0.2
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Find URLs in text and turn them into clickable links
WWW=		https://github.com/vstelmakh/url-highlight

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	vstelmakh
USE_PHP=	mbstring
IGNORE_WITH_PHP=	82 83

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pear/VStelmakh/UrlHighlight
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/pear/VStelmakh/UrlHighlight)

.include <bsd.port.mk>
