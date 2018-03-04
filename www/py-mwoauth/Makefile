# $FreeBSD$

PORTNAME=	mwoauth
DISTVERSION=	0.3.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic MediaWiki OAuth handshake helper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauthlib>0:security/py-oauthlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>0:www/py-pyjwt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>0:www/py-requests-oauthlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
