# $FreeBSD$

PORTNAME=	internetarchive
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.7-3
DISTVERSIONSUFFIX=	-g571765c
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to archive.org

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clint>=0.4.0:devel/py-clint@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0.6.0:devel/py-docopt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>=0.4:devel/py-jsonpatch@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schema>=0.4.0:devel/py-schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.0.0:devel/py-six@${FLAVOR}
py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.csv>0:devel/py-backports.csv@${FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	jjjake
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
