PORTNAME=	jonpy
DISTVERSION=	0.14
CATEGORIES=	www python
MASTER_SITES=	https://github.com/jribbens/${PORTNAME}/releases/download/rel-0-14/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python FastCGI interface library
WWW=		https://github.com/jribbens/jonpy

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTEXAMPLES=	* .htaccess

OPTIONS_DEFINE=	EXAMPLES

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
