# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	https://github.com/log2timeline/plaso/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline

LICENSE=	APACHE20

RUN_DEPENDS=	hachoir-core>=0:devel/hachoir-core \
		hachoir-metadata>=0:sysutils/hachoir-metadata \
		hachoir-parser>=0:devel/hachoir-parser \
		libesedb>=e:devel/libesedb \
		libevt>=a:devel/libevt \
		libevtx>=a:devel/libevtx \
		libfwsi>=e:devel/libfwsi \
		liblnk>=0:devel/liblnk \
		libmsiecf>=a:devel/libmsiecf \
		libolecf>=a:devel/libolecf \
		libregf>=a:devel/libregf \
		${PYTHON_PKGNAMEPREFIX}artifacts>=0:security/py-artifacts \
		${PYTHON_PKGNAMEPREFIX}bencode>=0:converters/py-bencode \
		${PYTHON_PKGNAMEPREFIX}binplist>=0:devel/py-binplist \
		${PYTHON_PKGNAMEPREFIX}construct>=0:devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}dfvfs>=0:security/py-dfvfs \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:net/py-dpkt \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}psutil121>=0:sysutils/py-psutil121 \
		${PYTHON_PKGNAMEPREFIX}pyelasticsearch>=0:textproc/py-pyelasticsearch \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	distutils autoplist

# Note: for regression tests set LANG to en_US.UTF-8

.include <bsd.port.mk>
