PORTNAME=	unreliablefs
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-
PATCH_SITES=	https://github.com/ligurio/unreliablefs/commit/
PATCHFILES=	a3caa832a5a63c69e18b8b66b503f9a460536539.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	FUSE-based fault injection filesystem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		fio:benchmarks/fio

USES=		cmake:testing fuse pkgconfig python:env
USE_CSTD=	c11
USE_GITHUB=	yes
GH_ACCOUNT=	ligurio

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}.conf.5.gz

post-patch:
# Upstream hardcodes FreeBSD release versions in order to skip some tests. We
# need to adjust those to values as not all supported FreeBSD releases are
# listed there.
	${REINPLACE_CMD} 's|freebsd12|freebsd${OSREL:R}|' \
		${WRKSRC}/tests/util.py \
		${WRKSRC}/tests/test_unreliablefs.py

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

do-test:
# The test suite assumes that the binaries are available in the ${WRKSRC}/build
# directory, which is not the case here.
	${MKDIR} ${WRKSRC}/build/tests
	${RLN} ${INSTALL_WRKSRC}/${PORTNAME} ${WRKSRC}/build/
	${RLN} ${INSTALL_WRKSRC}/tests/fsx ${WRKSRC}/build/tests
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest --verbose -rxXs tests/

.include <bsd.port.mk>
