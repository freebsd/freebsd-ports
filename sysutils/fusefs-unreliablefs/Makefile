PORTNAME=	unreliablefs
DISTVERSION=	0.2.0
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-
PATCH_SITES=	https://github.com/ligurio/unreliablefs/commit/
PATCHFILES=	e97d259b1cda3c1342c9cb472d31230e50b0776d.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	FUSE-based fault injection filesystem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		fio:benchmarks/fio

USES=		compiler:c++11-lang cmake fuse pkgconfig python:env
USE_CSTD=	c11
USE_GITHUB=	yes
GH_ACCOUNT=	ligurio

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}.conf.5.gz

do-test:
# fusefs(5) must be loaded.
	if ! kldload -n fusefs; then \
		${ECHO_MSG} "Cannot load the fusefs kernel module"; \
		${FALSE}; \
	fi
# /dev/fuse must be writtable and readable to the user running the tests.
	if [ ! -r /dev/fuse ] || [ ! -w /dev/fuse ]; then \
		${ECHO_MSG} "Current user does cannot access /dev/fuse"; \
		${FALSE}; \
	fi
# The test suite assumes that the binaries are available in the ${WRKSRC}/build
# directory, which is not the case here.
	${LN} -Fs ${INSTALL_WRKSRC} ${WRKSRC}/build
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest --verbose -rxXs tests/

.include <bsd.port.mk>
