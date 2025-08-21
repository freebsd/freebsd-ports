PORTNAME=	varnish
DISTVERSION=	7.7.3
CATEGORIES=	www
MASTER_SITES=	https://varnish-cache.org/downloads/
PKGNAMESUFFIX=	7

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	High-performance HTTP accelerator
WWW=		https://varnish-cache.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		cpe libedit libtool localbase ncurses pathfix \
		pkgconfig python:build shebangfix tar:tgz
CPE_VENDOR=	varnish-cache
CPE_PRODUCT=	varnish_cache
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
SHEBANG_FILES=	lib/libvcc/*.py lib/libvsc/*.py
USE_LDCONFIG=	yes
USE_RC_SUBR=	varnishd varnishlog varnishncsa
CONFLICTS=	varnish4 varnish6

SUB_FILES=	pkg-message

USERS=		varnish varnishlog
GROUPS=		varnish

INSTALL_TARGET=	install-strip
TEST_TARGET=	check
TEST_ARGS=	TESTS_PARALLELISM=1

CONFIGURE_ARGS=	--localstatedir=${PREFIX} --without-dot
# Needed for clang 15 (#268814)
CONFIGURE_ENV+=	ax_cv_check_cflags___Werror=no

.if defined(NO_INET6) || defined(WITHOUT_INET6)
BAD_TESTS=	r00832
EXTRA_PATCHES=	${FILESDIR}/no-inet6.patch
.endif

OPTIONS_DEFINE=	DOCS

post-patch:
.if defined(BAD_TESTS)
	${RM} ${BAD_TESTS:C|.+|${WRKSRC}/bin/varnishtest/tests/\0.vtc|}
.endif

.include <bsd.port.mk>
