# New ports collection makefile for:	varnish
# Date created:				2006-08-11
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	varnish
PORTVERSION=	3.0.1
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	The Varnish high-performance HTTP accelerator

LICENSE=	BSD

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFLICTS=	varnish-2.*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON_BUILD=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}
CONFIGURE_ENV=	RST2MAN=true
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=  aclocal libtool libtoolize autoheader automake autoconf
ACLOCAL_ARGS=	-I m4
LIBTOOLFLAGS=	--copy --force
AUTOMAKE_ARGS=	--add-missing --copy --foreign

MAN1=		varnishadm.1 varnishd.1 varnishhist.1 varnishlog.1 \
		varnishncsa.1 varnishreplay.1 varnishsizes.1 \
		varnishstat.1 varnishtest.1 varnishtop.1
MAN3=		vmod_std.3
MAN7=		vcl.7 varnish-cli.7
USE_RC_SUBR=	varnishd varnishlog varnishncsa
SUB_FILES=	pkg-message

.if defined(WITH_VARNISHNCSA_B)
# I still find a use for varnishncsa -b, even though Varnish developers does
# not seem to want to keep this option. - anders@FreeBSD.org 2011-08-31
PATCH_SITES+=	http://anders.fupp.net/distfiles/:ncsab
PATCHFILES+=	patch-varnishncsa-3.0.0.diff:ncsab
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${PREFIX}/share/varnish
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/libvmod_std/vmod.py ${PREFIX}/share/varnish
.for f in cache.h heritage.h steps.h common.h acct_fields.h locks.h
	@${INSTALL_DATA} ${WRKSRC}/bin/varnishd/${f} ${PREFIX}/include/varnish
.endfor
.for f in vct.h vmod_abi.h vrt.h vqueue.h vsb.h libvarnish.h miniobj.h vas.h vav.h http_headers.h vcl_returns.h
	@${INSTALL_DATA} ${WRKSRC}/include/${f} ${PREFIX}/include/varnish
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
