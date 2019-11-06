# $FreeBSD$

PORTNAME=	s3ql
PORTVERSION=	2.21
CATEGORIES=	net
MASTER_SITES=	https://bitbucket.org/nikratio/s3ql/downloads/

MAINTAINER=	stdin@niklaas.eu
COMMENT=	File system that stores all its data in the cloud

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apsw>=3.7:databases/py-apsw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llfuse>=0:devel/py-llfuse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dugong>=0:net/py-dugong@${PY_FLAVOR} \
		psmisc>=0:sysutils/psmisc \
		ca_root_nss>=0:security/ca_root_nss
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		compiler:c++11-lang localbase python:3.3+ sqlite tar:bz2
USE_PYTHON=	autoplist distutils optsuffix

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/s3ql/deltadump.so

.include <bsd.port.mk>
