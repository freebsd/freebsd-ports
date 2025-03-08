PORTNAME=	libcloud
PORTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	APACHE/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Standard client library for many popular cloud providers
WWW=		https://libcloud.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.5.0:www/py-requests@${PY_FLAVOR}

NO_ARCH=	yes

USES=		cpe python
USE_PYTHON=	distutils autoplist
CPE_VENDOR=	apache

post-extract:
	@${MV} ${WRKSRC}/libcloud/test ${WRKSRC}/test # no need to install tests

.include <bsd.port.mk>
