# $FreeBSD$

PORTNAME=	peda
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1-19
DISTVERSIONSUFFIX=	-g7f673be
CATEGORIES=	security python

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Python-based GDB extension for exploit development and debugging

LICENSE=	CC-BY-NC-SA-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gdb>7.0:devel/gdb \
		nasm:devel/nasm \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		python:2.6+,run

USE_GITHUB=	yes
GH_ACCOUNT=	longld

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	LIBEXECDIR=${LIBEXECDIR} UTILITY_NAME=${UTILITY_NAME}

OPTIONS_DEFINE=	DOCS

UTILITY_NAME=	${PORTNAME}.py
LIBEXECDIR=	${PREFIX}/libexec/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${LIBEXECDIR}
	${INSTALL_DATA} ${WRKSRC}/${UTILITY_NAME} ${STAGEDIR}${LIBEXECDIR}
	${MKDIR} ${STAGEDIR}${LIBEXECDIR}/lib
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${LIBEXECDIR}/lib

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README README.md python23-compatibility.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
