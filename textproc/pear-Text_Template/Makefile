PORTNAME=	Text_Template
PORTVERSION=	3.0.1
CATEGORIES=	textproc www pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple template engine
WWW=		https://pear.phpunit.de/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	share/PHP/Text_Template/Template.php

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	php-text-template

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/PHP/Text_Template
	${INSTALL_SCRIPT} ${WRKSRC}/src/Template.php ${STAGEDIR}${PREFIX}/share/PHP/Text_Template

.include <bsd.port.mk>
