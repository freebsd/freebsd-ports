# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	5.2.0
DISTVERSIONPREFIX=	varnish-
PORTREVISION=	0
CATEGORIES=	www
PKGNAMESUFFIX=	5

MAINTAINER=	feld@FreeBSD.org
COMMENT=	High-performance HTTP accelerator

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libpcre.so:devel/pcre

CONFLICTS=	varnish-2.* varnish-3.* varnish4-4.*

USES=		autoreconf cpe gmake libedit libtool ncurses pathfix \
		pkgconfig python:2,build readline shebangfix
SHEBANG_FILES=	lib/libvcc/*.py
CPE_VENDOR=	varnish-cache
CFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX} --without-dot
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

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

post-patch:
.if defined(BAD_TESTS)
	${RM} ${BAD_TESTS:C|.+|${WRKSRC}/bin/varnishtest/tests/\0.vtc|}
.endif

regression-test check test: build
	${MAKE_CMD} TESTS_PARALLELISM=1 -C ${WRKSRC} check

.include <bsd.port.mk>
