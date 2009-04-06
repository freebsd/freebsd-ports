# New ports collection makefile for:	varnish
# Date created:				2006-08-11
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	varnish
PORTVERSION=	2.0.4
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	des@FreeBSD.org
COMMENT=	The Varnish high-performance HTTP accelerator

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}
USE_LDCONFIG=	yes

MAN1=		varnishadm.1 varnishd.1 varnishhist.1 varnishlog.1 \
		varnishncsa.1 varnishreplay.1 varnishstat.1 varnishtest.1 \
		varnishtop.1
MAN7=		vcl.7
USE_RC_SUBR=	varnishd varnishlog varnishncsa

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
