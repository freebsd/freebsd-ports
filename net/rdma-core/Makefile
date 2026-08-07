PORTNAME=	rdma-core
PORTVERSION=	65.0
CATEGORIES=	net sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Remote Direct Memory Access core userspace libraries and daemons
WWW=		https://github.com/linux-rdma/rdma-core

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/COPYING.BSD_MIT
LICENSE_FILE_GPLv2=		${WRKSRC}/COPYING.GPL2

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libudev.so:devel/libudev-devd

USES=		cmake pkgconfig python:env,test shebangfix

# Use GNU ld to workaround the linker script problem
# ld: error: version script assignment of 'global' to symbol 'fcntl64' failed: symbol not defined
LLD_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kostikbel
GH_TAGNAME=	102be747b8dbb9b86f454cd1af432b5d7f6e21be

CMAKE_ARGS=	-DIOCTL_MODE=write
CMAKE_OFF=	ENABLE_RESOLVE_NEIGH

SHEBANG_FILES=	kernel-boot/rdma_topo \
		providers/ipathverbs/truescale-serdes.cmds \
		infiniband-diags/scripts/*.pl \
		srp_daemon/*.in \
		tests/run_tests.py

OPTIONS_DEFINE=		DOCS MANPAGES PYVERBS TEST
OPTIONS_DEFAULT=	MANPAGES PYVERBS
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc \
			rst2man:textproc/py-docutils@${PY_FLAVOR}
MANPAGES_CMAKE_BOOL_OFF=NO_MAN_PAGES

PYVERBS_DESC=		Enable python bindings
PYVERBS_LIB_DEPENDS=	libdrm.so:graphics/libdrm
PYVERBS_USES=		python:build,run
PYVERBS_USE=		python=cython
PYVERBS_CMAKE_BOOL_OFF=	NO_PYVERBS

TEST_IMPLIES=		PYVERBS

post-install:
	@${RM} -r ${STAGEDIR}/usr/lib
	@${RM} -r ${STAGEDIR}${PREFIX}/etc/init.d
	@${RM} -r ${STAGEDIR}${PREFIX}/etc/modprobe.d
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/udev

do-test-TEST-on:
	cd ${WRKSRC} && ${PYTHON_CMD} tests/run_tests.py

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1501000
IGNORE=		Requires tdestroy(3) in libc
.endif

.include <bsd.port.post.mk>
