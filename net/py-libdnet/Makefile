# Created by: thierry@pompo.net
# $FreeBSD$

CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for libdnet

LIB_DEPENDS=	libdnet.so:${PORTSDIR}/net/libdnet

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON_ia64=	fails to build with internal compiler error

MASTERDIR=	${.CURDIR}/../libdnet
INSTALL_WRKSRC=	${WRKSRC}/python
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${NONEXISTENT}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/dnet.so \
		%%PYTHON_SITELIBDIR%%/dnet-${PORTVERSION}-py${PYTHON_VER}.egg-info

LIBDNET_SLAVE=	yes

USES=		python
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD}

.if defined(MAINTAINER_MODE)
regression-test: install
	${PYTHON_CMD} ${INSTALL_WRKSRC}/test.py
.endif

.include "${MASTERDIR}/Makefile"
