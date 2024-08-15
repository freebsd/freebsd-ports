PORTNAME=	Text_Template
PORTVERSION=	4.0.1
CATEGORIES=	textproc www pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple template engine
WWW=		https://github.com/sebastianbergmann/php-text-template

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	php-text-template

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
