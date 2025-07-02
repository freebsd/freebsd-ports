PORTNAME=	rasqal
PORTVERSION=	0.9.33
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/ \
		SF/librdf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	High-level interface for RDF
WWW=		https://librdf.org/

# Even though GPLv3 is not explicitly mentioned in the port's LICENSE.html, one
# of its licenses is "GPLv2 or newer", which includes GPLv3.
LICENSE=	APACHE20 GPLv2 GPLv3 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libraptor2.so:textproc/raptor2 \
		libpcre.so:devel/pcre

USES=		gmake libtool pathfix perl5 pkgconfig ssl
USE_PERL5=	build
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

OPTIONS_RADIO=	DEC
OPTIONS_RADIO_DEC=	GMP MPFR

GMP_DESC=	Use GMP library for decimals
MPFR_DESC=	Use MPFR library for decimals

GMP_CONFIGURE_ON=	--with-decimal=gmp --with-gmp=${LOCALBASE}
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
MPFR_CONFIGURE_ON=	--with-decimal=mpfr --with-mpfr=${LOCALBASE}
MPFR_LIB_DEPENDS=	libmpfr.so:math/mpfr

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MMPFR) && empty(PORT_OPTIONS:MGMP)
CONFIGURE_ARGS+=--with-decimal=none
.endif

.include <bsd.port.mk>
