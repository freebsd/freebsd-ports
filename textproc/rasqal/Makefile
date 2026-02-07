PORTNAME=	rasqal
PORTVERSION=	0.9.33
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	https://download.librdf.org/source/

MAINTAINER=	office@FreeBSD.org
COMMENT=	RDF Query Library
WWW=		https://librdf.org/rasqal/

LICENSE=	APACHE20 GPLv2+ LGPL21+
LICENSE_COMB=	dual

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libraptor2.so:textproc/raptor2

USES=		gmake libtool localbase pathfix perl5 pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-pcre \
		--with-digest-library=gcrypt \
		--with-uuid-library=internal
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	MPFR
OPTIONS_SINGLE=		DEC
OPTIONS_SINGLE_DEC=	GMP MPFR NONE

DEC_DESC=	Library to support XSD decimal type
GMP_DESC=	Use GMP library for decimals
MPFR_DESC=	Use MPFR library for decimals
NONE_DESC=	Use IEEE double precision (nonconforming)

GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_ON=	--with-decimal=gmp
MPFR_LIB_DEPENDS=	libmpfr.so:math/mpfr
MPFR_CONFIGURE_ON=	--with-decimal=mpfr
NONE_CONFIGURE_ON=	--with-decimal=none

.include <bsd.port.mk>
