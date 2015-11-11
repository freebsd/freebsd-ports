# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	https://github.com/log2timeline/plaso/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline

LICENSE=	APACHE20

RUN_DEPENDS=	hachoir-core>=0:${PORTSDIR}/devel/hachoir-core \
		hachoir-metadata>=0:${PORTSDIR}/sysutils/hachoir-metadata \
		hachoir-parser>=0:${PORTSDIR}/devel/hachoir-parser \
		libesedb>=e:${PORTSDIR}/devel/libesedb \
		libevt>=a:${PORTSDIR}/devel/libevt \
		libevtx>=a:${PORTSDIR}/devel/libevtx \
		libfwsi>=e:${PORTSDIR}/devel/libfwsi \
		liblnk>=0:${PORTSDIR}/devel/liblnk \
		libmsiecf>=a:${PORTSDIR}/devel/libmsiecf \
		libolecf>=a:${PORTSDIR}/devel/libolecf \
		libregf>=a:${PORTSDIR}/devel/libregf \
		${PYTHON_PKGNAMEPREFIX}artifacts>=0:${PORTSDIR}/security/py-artifacts \
		${PYTHON_PKGNAMEPREFIX}bencode>=0:${PORTSDIR}/converters/py-bencode \
		${PYTHON_PKGNAMEPREFIX}binplist>=0:${PORTSDIR}/devel/py-binplist \
		${PYTHON_PKGNAMEPREFIX}construct>=0:${PORTSDIR}/devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}dfvfs>=0:${PORTSDIR}/security/py-dfvfs \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:${PORTSDIR}/net/py-dpkt \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:${PORTSDIR}/devel/ipython \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:${PORTSDIR}/devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:${PORTSDIR}/devel/py-pefile \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}psutil121>=0:${PORTSDIR}/sysutils/py-psutil121 \
		${PYTHON_PKGNAMEPREFIX}pyelasticsearch>=0:${PORTSDIR}/textproc/py-pyelasticsearch \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:${PORTSDIR}/sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml

USES=		python:2
USE_PYTHON=	distutils autoplist

# Note: for regression tests set LANG to en_US.UTF-8

.include <bsd.port.mk>
