PORTNAME=	pacparser
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.6
CATEGORIES=	www

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library to parse proxy auto-config (PAC) files
WWW=		https://github.com/manugarg/pacparser

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	manugarg
USE_LDCONFIG=	yes

MAKE_ENV+=	NO_INTERNET=1
MAKE_JOBS_UNSAFE=	yes

WRKSRC_SUBDIR=	src

PLIST_SUB=	VER=${PORTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_DEFAULT=	PYTHON

PYTHON_BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
PYTHON_USES=		python
PYTHON_MAKE_ENV+=	PYTHON=${PYTHON_CMD}

PYTHON_ALL_TARGET=	all pymod
PYTHON_INSTALL_TARGET=	install install-pymod

PYTHON_PLIST_SUB=	PYBIND=""
PYTHON_PLIST_SUB_OFF=	PYBIND="@comment "

post-patch-PYTHON-on:
	@${REINPLACE_CMD} \
		-e "s|version=pacparser_version()|version=\"${DISTVERSION}\"|" \
		${WRKSRC}/pymod/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pactester
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpacparser.so.1

post-install-PYTHON-on:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pacparser/_pacparser.cpython-*.so

do-test-PYTHON-on:
	${PYTHON_CMD} ${WRKSRC}/../tests/runtests.py

.include <bsd.port.mk>
