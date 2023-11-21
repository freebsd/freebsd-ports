PORTNAME=	openzfs
PORTVERSION=	2023113000
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	freqlabs@FreeBSD.org
COMMENT=	OpenZFS userland for FreeBSD
WWW=		https://github.com/openzfs/zfs

LICENSE=	CDDL

BROKEN_aarch64=	invokes x86 assembler
BROKEN_riscv64=	fails to compile: btree_test.c:462:49: result of comparison of constant -1 with expression of type 'char' is always true

BUILD_DEPENDS=	ksh93:shells/ksh93
RUN_DEPENDS=	openzfs-kmod>=0:sysutils/openzfs-kmod

USES+=		autoreconf:build cpe libtool gmake gettext-runtime python:build shebangfix ssl
SHEBANG_GLOB=	*.ksh *.ksh.in *.kshlib *.py.in
SHEBANG_FILES=	tests/zfs-tests/tests/functional/trim/trim.cfg \
		cmd/arcstat.in \
		cmd/dbufstat.in \
		cmd/zilstat.in \
		cmd/arc_summary

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	MAKE=gmake --prefix=${PREFIX} --with-config="user"

OPTIONS_DEFINE=	DEBUG PYTHON TESTS
PYTHON_DESC=	Build the pyzfs library, arc_summary, arcstat, and dbufstat utilities
TESTS_DESC=	Install the ZFS Test Suite
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_PROJECT=	zfs
GH_TAGNAME=	494aaae

USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-debuginfo
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PYTHON_VER}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR}
.else
CONFIGURE_ARGS+=	--without-python
PYTHON_NO_DEPENDS=yes
.endif

post-extract:
	# Change certain shebangs into something that shebang fix understands
	cd ${WRKSRC} && ${SED} -i '' '1s:@PYTHON_SHEBANG@:python3:' \
		tests/test-runner/bin/zts-report.py.in \
		tests/test-runner/bin/test-runner.py.in \
		cmd/arcstat.in \
		cmd/dbufstat.in \
		cmd/zilstat.in

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
