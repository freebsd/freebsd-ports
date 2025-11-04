PORTNAME=	lcalc
DISTVERSION=	2.1.1
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	L-function c++ class library and the CLI program lcalc
WWW=		https://gitlab.com/sagemath/lcalc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/COPYING

BUILD_DEPENDS=	gengetopt:devel/gengetopt
LIB_DEPENDS=	libpari.so:math/pari

USES=		autoreconf compiler:c++11-lang gmake libtool localbase	\
		pkgconfig tar:bz2
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	sagemath

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--with-pari \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=	DOCS EXAMPLES

post-configure:
	${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(docdir)|${STAGEDIR}${EXAMPLESDIR}|g' \
	    ${PATCH_WRKSRC}/doc/examples/Makefile
	${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(docdir)|${STAGEDIR}${EXAMPLESDIR}/data|g' \
	    ${PATCH_WRKSRC}/doc/examples/*/Makefile

.include <bsd.port.mk>
