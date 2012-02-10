# New ports collection makefile for:	varnish
# Date created:				2006-08-11
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	varnish
PORTVERSION=	3.0.2
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
USE_AUTOTOOLS=  aclocal libtool libtoolize automake autoconf
ACLOCAL_ARGS=	-I m4
LIBTOOLFLAGS=	--copy --force
AUTOMAKE_ARGS=	--add-missing --copy --foreign

MAN1=		varnishadm.1 varnishd.1 varnishhist.1 varnishlog.1 \
		varnishncsa.1 varnishreplay.1 varnishsizes.1 \
		varnishstat.1 varnishtest.1 varnishtop.1
MAN3=		vmod_std.3
MAN7=		vcl.7 varnish-cli.7 varnish-counters.7
USE_RC_SUBR=	varnishd varnishlog varnishncsa
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${PREFIX}/share/varnish
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/libvmod_std/vmod.py ${PREFIX}/share/varnish
.for f in cache.h heritage.h steps.h common.h acct_fields.h locks.h body_status.h
	@${INSTALL_DATA} ${WRKSRC}/bin/varnishd/${f} ${PREFIX}/include/varnish
.endfor
.for f in vct.h vmod_abi.h vrt.h vqueue.h vsb.h libvarnish.h miniobj.h vas.h vav.h http_headers.h vcl_returns.h
	@${INSTALL_DATA} ${WRKSRC}/include/${f} ${PREFIX}/include/varnish
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
