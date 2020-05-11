# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	6.4.0
DISTVERSIONPREFIX=	varnish-
CATEGORIES=	www
PKGNAMESUFFIX=	6

MAINTAINER=	feld@FreeBSD.org
COMMENT=	High-performance HTTP accelerator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils \
		${PY_SPHINX}
LIB_DEPENDS=	libpcre.so:devel/pcre

CONFLICTS=	varnish-2.* varnish-3.* varnish4-4.* varnish5-5.*

USES=		autoreconf compiler cpe gmake libedit libtool ncurses pathfix \
		pkgconfig python:3.4+,build readline shebangfix
SHEBANG_FILES=	lib/libvcc/*.py
CPE_VENDOR=	varnish-cache
CFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX} --without-dot
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
TEST_ARGS=	TESTS_PARALLELISM=1

USE_GITHUB=	yes
GH_ACCOUNT=	varnishcache
GH_PROJECT=	varnish-cache

USERS=		varnish varnishlog
GROUPS=		varnish

USE_RC_SUBR=	varnishd varnishlog varnishncsa
.if defined(NO_INET6) || defined(WITHOUT_INET6)
BAD_TESTS+=	r00832
EXTRA_PATCHES+=	${FILESDIR}/no-inet6.patch
.endif

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
.if defined(BAD_TESTS)
	${RM} ${BAD_TESTS:C|.+|${WRKSRC}/bin/varnishtest/tests/\0.vtc|}
.endif
.if ${CHOSEN_COMPILER_TYPE} == gcc
	${REINPLACE_CMD} -e '/-Wno-unknown-warning-option -Wno-implicit-fallthrough/d' ${WRKSRC}/configure.ac
.endif

.include <bsd.port.post.mk>
