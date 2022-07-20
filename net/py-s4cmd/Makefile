PORTNAME=	s4cmd
DISTVERSION=	2.1.0-11
DISTVERSIONSUFFIX=	-ge74e0e7
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command line client for S3 storage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.3.1:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.4:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	bloomreach
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
