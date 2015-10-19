# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	4.1.0
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/
PKGNAMESUFFIX=	4

MAINTAINER=	feld@FreeBSD.org
COMMENT=	High-performance HTTP accelerator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libedit.so.0:${PORTSDIR}/devel/libedit

CONFLICTS=	varnish-2.* varnish-3.*

USES=		autoreconf cpe gmake libtool pkgconfig python:2,build readline shebangfix
SHEBANG_FILES=	lib/libvcc/vmodtool.py
CPE_VENDOR=	varnish-cache
CFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX} --enable-tests
CONFIGURE_ENV=	RST2MAN=true
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USERS=		varnish varnishlog
GROUPS=		varnish

USE_RC_SUBR=	varnishd varnishlog varnishncsa
SUB_FILES=	pkg-message
.if defined(NO_INET6) || defined(WITHOUT_INET6)
BAD_TESTS+=	r00832
EXTRA_PATCHES+=	${FILESDIR}/no-inet6.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am
.if defined(BAD_TESTS)
	${RM} -f ${BAD_TESTS:C|.+|${WRKSRC}/bin/varnishtest/tests/\0.vtc|}
.endif

regression-test check test: build
	${MAKE_CMD} TESTS_PARALLELISM=1 -C ${WRKSRC} check

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not configure on arm
.endif

.include <bsd.port.post.mk>
