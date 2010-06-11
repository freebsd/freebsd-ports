# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#
PORTNAME=	rasqal
PORTVERSION=	0.9.19
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/librdf/${PORTNAME}/${PORTVERSION} \
		http://librdf.org/dist/source/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A high-level interface for RDF

LIB_DEPENDS=	raptor.3:${PORTSDIR}/textproc/raptor \
		pcre.0:${PORTSDIR}/devel/pcre

USE_GNOME=	gnomehack gnometarget lthack pkgconfig
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-raptor=system

USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

MAN1=		rasqal-config.1 roqet.1
MAN3=		librasqal.3

OPTIONS+=	MPFR  "Use MPFR library for decimals (implies GMP)" off
OPTIONS+=	GMP   "Use Gnu MP library for decimals" off

.include <bsd.port.options.mk>

# Set to mpfr if MPFR is on, gmp if only GMP is on and none if neither.
# This guards against $user setting both GMP and MPFR, since we can't be
# very verbose in explaining our options.
.if defined(WITH_MPFR)
CONFIGURE_ARGS+=	--with-decimal=mpfr
LIB_DEPENDS+=	mpfr.4:${PORTSDIR}/math/mpfr
.elif defined(WITH_GMP)
CONFIGURE_ARGS+=	--with-decimal=gmp
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
.else
CONFIGURE_ARGS+=	--with-decimal=none
.endif

.include <bsd.port.mk>
