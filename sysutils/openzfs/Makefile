# $FreeBSD$

PORTNAME=	openzfs
PORTVERSION=	2020050800
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	freqlabs@FreeBSD.org
COMMENT=	OpenZFS userland for FreeBSD

LICENSE=	CDDL

BROKEN_aarch64=	invokes x86 assembler

RUN_DEPENDS=	openzfs-kmod>=0:sysutils/openzfs-kmod

USES+=		autoreconf:build libtool gmake gettext-runtime:run python:3.3+,build shebangfix

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-config="user"

OPTIONS_DEFINE=	DEBUG PYTHON TESTS
DEBUG_DESC=	Build a debug configuration
PYTHON_DESC=	Build the pyzfs library, arc_summary and arcstat utilities
TESTS_DESC=	Install the ZFS Test Suite
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	openzfs
GH_PROJECT=	zfs
GH_TAGNAME=	1cc635a2d

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 1200504) || (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300013)
IGNORE=	needs FreeBSD 12/13 with AES-CCM support
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-debuginfo
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PYTHON_VER}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR}
.else
CONFIGURE_ARGS+=	--without-python
.endif

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.post.mk>
