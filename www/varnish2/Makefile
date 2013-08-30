# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	2.1.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	The Varnish high-performance HTTP accelerator

LICENSE=	BSD

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre

LATEST_LINK=	varnish2
CONFLICTS=	varnish-3.*

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
CONFIGURE_ARGS=	--localstatedir=${PREFIX}
CONFIGURE_ENV=	RST2MAN=true
USE_LDCONFIG=	yes

MAN1=		varnishadm.1 varnishd.1 varnishhist.1 varnishlog.1 \
		varnishncsa.1 varnishreplay.1 varnishsizes.1 \
		varnishstat.1 varnishtest.1 varnishtop.1
MAN7=		vcl.7
USE_RC_SUBR=	varnishd varnishlog varnishncsa
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
