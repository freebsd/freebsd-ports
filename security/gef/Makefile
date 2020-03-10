# $FreeBSD$

PORTNAME=	gef
DISTVERSION=	2020.03-1
CATEGORIES=	security python

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	GDB Enhanced Features for exploit devs & reversers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gdb>7.7:devel/gdb

USES=		python:run

USE_GITHUB=	yes
GH_ACCOUNT=	hugsy

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	UTILITY_NAME=${_UTILITY_NAME}

PLIST_FILES=	${DATADIR_REL}/${_UTILITY_NAME}

OPTIONS_DEFINE=		OPTIONALDEPS
OPTIONS_DEFAULT=	OPTIONALDEPS

OPTIONALDEPS_DESC=		Install optional dependencies for extra functionalities
OPTIONALDEPS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>0:devel/py-capstone@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}keystone-engine>0:devel/py-keystone-engine@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}ropper>0:security/py-ropper@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}unicorn>0:emulators/py-unicorn@${PY_FLAVOR}

_UTILITY_NAME=	gef.py

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${_UTILITY_NAME} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
