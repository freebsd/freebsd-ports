# $FreeBSD$

PORTNAME=	rtv
PORTVERSION=	1.20.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Commandline client for reddit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kitchen>=1.2.4:devel/py-kitchen@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.5.1:www/py-beautifulsoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=4.0.10:devel/py-decorator@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	michael-lazar

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist concurrent optsuffix

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mailcap_fix>=0.1.3:devel/py-mailcap-fix@${FLAVOR}
.endif

.include <bsd.port.post.mk>
