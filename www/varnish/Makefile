# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	3.0.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	The Varnish high-performance HTTP accelerator

LICENSE=	BSD

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

CONFLICTS=	varnish-2.*

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_PYTHON_BUILD=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX} --enable-tests
CONFIGURE_ENV=	RST2MAN=true
USE_LDCONFIG=	yes
USE_AUTOTOOLS=  aclocal libtool libtoolize automake autoconf
ACLOCAL_ARGS=	-I m4
LIBTOOLFLAGS=	--copy --force --disable-static
AUTOMAKE_ARGS=	--add-missing --copy --foreign

MAN1=		varnishadm.1 varnishd.1 varnishhist.1 varnishlog.1 \
		varnishncsa.1 varnishreplay.1 varnishsizes.1 \
		varnishstat.1 varnishtest.1 varnishtop.1
MAN3=		vmod_std.3
MAN7=		vcl.7 varnish-cli.7 varnish-counters.7
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
	${GMAKE} TESTS_PARALLELISM=1 -C ${WRKSRC} check

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
	@${MKDIR} ${PREFIX}/share/varnish
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/libvmod_std/vmod.py ${PREFIX}/share/varnish
.for f in cache.h heritage.h steps.h common.h acct_fields.h locks.h body_status.h
	@${INSTALL_DATA} ${WRKSRC}/bin/varnishd/${f} ${PREFIX}/include/varnish
.endfor
.for f in vct.h vmod_abi.h vre.h vrt.h vqueue.h vsb.h libvarnish.h miniobj.h vas.h vav.h http_headers.h vcl_returns.h
	@${INSTALL_DATA} ${WRKSRC}/include/${f} ${PREFIX}/include/varnish
.endfor
	@${CAT} ${PKGMESSAGE}
	@${RM} -f ${PREFIX}/lib/libvarnishapi.*a ${PREFIX}/lib/varnish/lib*a ${PREFIX}/lib/varnish/vmods/lib*a

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
EXTRA_PATCHES+=	${FILESDIR}/bug-1201.patch
.endif
.if ${ARCH} == "arm"
BROKEN=		Does not configure on arm
.endif

.include <bsd.port.post.mk>
