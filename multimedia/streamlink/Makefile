# $FreeBSD$

PORTNAME=	streamlink
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	takefu@airport.fm
COMMENT=	Command-line utility that pipes video streams

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>0:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.4.3:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks${PY_FLAVOUR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>0:devel/py-backports@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}country>0:devel/py-country@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR}

# The upstream port would in theory support python 2.7, but deprecates use of streamlink
# on it, there are 4 additional RUN_DEPENDS, and also one of the self-tests fails on 2.7
# but not 3.7, and is encoding-related, so to avoid run-time issues, limit to >= 3.5.
USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		FFMPEG PYCOUNTRY RTMPDUMP
OPTIONS_DEFAULT=	FFMPEG RTMPDUMP
.if !exists(../../textproc/py-iso3166/Makefile)
OPTIONS_DEFAULT+=	PYCOUNTRY
.endif
PYCOUNTRY_DESC=		Use pycountry instead of py-iso-639 and py-iso3166

FFMPEG_RUN_DEPENDS=		ffmpeg:multimedia/ffmpeg
PYCOUNTRY_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}country>0:devel/py-country@${PY_FLAVOR}
PYCOUNTRY_RUN_DEPENDS_OFF=	${PYTHON_PKGNAMEPREFIX}iso-639>0:textproc/py-iso-639@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}iso3166>0:textproc/py-iso3166@${PY_FLAVOR}
PYCOUNTRY_MAKE_ENV=		STREAMLINK_USE_PYCOUNTRY=1
RTMPDUMP_RUN_DEPENDS=		rtmpdump:multimedia/rtmpdump

do-test:	.PHONY
		cd ${WRKSRC} && ${SETENV} PYTHONPATH=${WRKSRC}/src ${PYTHON_CMD} -u -m pytest -v -ra \
		|| ${SETENV} PYTHONPATH=${WRKSRC}/src ${PYTHON_CMD} -um unittest discover -v

.include <bsd.port.mk>
