# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	3.0.5
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Varnish high-performance HTTP accelerator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

CONFLICTS=	varnish-2.*

GNU_CONFIGURE=	yes
USES=		gmake libtool readline pkgconfig
USE_PYTHON_BUILD=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX} --enable-tests
CONFIGURE_ENV=	RST2MAN=true
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal libtoolize automake autoconf
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	--add-missing --copy --foreign
INSTALL_TARGET=	install-strip

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

post-build:
	#
	# It is highly recommended, that you verify the build's
	# correctness by performing:
	#
	#	make check
	#
	# now...
	#

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/varnish
	${INSTALL_SCRIPT} ${WRKSRC}/lib/libvmod_std/vmod.py ${STAGEDIR}${PREFIX}/share/varnish
.for f in cache.h heritage.h steps.h common.h acct_fields.h locks.h body_status.h
	${INSTALL_DATA} ${WRKSRC}/bin/varnishd/${f} ${STAGEDIR}${PREFIX}/include/varnish
.endfor
.for f in vct.h vmod_abi.h vre.h vrt.h vqueue.h vsb.h libvarnish.h miniobj.h vas.h vav.h http_headers.h vcl_returns.h
	${INSTALL_DATA} ${WRKSRC}/include/${f} ${STAGEDIR}${PREFIX}/include/varnish
.endfor
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/libvarnishapi.*a ${STAGEDIR}${PREFIX}/lib/varnish/lib*a ${STAGEDIR}${PREFIX}/lib/varnish/vmods/lib*a
	@${MV} ${STAGEDIR}${ETCDIR}/default.vcl ${STAGEDIR}${ETCDIR}/default.vcl.sample

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
EXTRA_PATCHES+=	${FILESDIR}/bug-1201.patch
.endif
.if ${ARCH} == "arm"
BROKEN=		Does not configure on arm
.endif

.include <bsd.port.post.mk>
