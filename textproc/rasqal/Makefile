# Created by: ijliao
# $FreeBSD$

PORTNAME=	rasqal
PORTVERSION=	0.9.30
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/ \
		SF/librdf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level interface for RDF

LIB_DEPENDS=	raptor2:${PORTSDIR}/textproc/raptor2 \
		pcre:${PORTSDIR}/devel/pcre

USE_GNOME=	gnomehack lthack
USE_OPENSSL=	yes
USE_PERL5_BUILD=yes
USE_PKGCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		rasqal-config.1 roqet.1
MAN3=		librasqal.3

OPTIONS_RADIO=	DEC
OPTIONS_RADIO_DEC=	GMP MPFR

GMP_DESC=	Use GMP library for decimals
MPFR_DESC=	Use MPFR library for decimals

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPFR}
CONFIGURE_ARGS+=--with-decimal=mpfr --with-mpfr=${LOCALBASE}
LIB_DEPENDS+=	mpfr:${PORTSDIR}/math/mpfr
.elif ${PORT_OPTIONS:MGMP}
CONFIGURE_ARGS+=--with-decimal=gmp
LIB_DEPENDS+=	gmp:${PORTSDIR}/math/gmp
.else
CONFIGURE_ARGS+=--with-decimal=none
.endif

.include <bsd.port.mk>
