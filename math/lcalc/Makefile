PORTNAME=	lcalc
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://mirror.csclub.uwaterloo.ca/sage/spkg/upstream/${PORTNAME}/ \
		https://mirror.lyrahosting.com/sagemath/spkg/upstream/${PORTNAME}/ \
		https://mirror.dogado.de/sage/spkg/upstream/${PORTNAME}/ \
		http://files.sagemath.org/spkg/upstream/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	L-function c++ class library and the CLI program lcalc
WWW=		https://gitlab.com/sagemath/lcalc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/COPYING

BUILD_DEPENDS=	gengetopt:devel/gengetopt
LIB_DEPENDS=	libpari.so:math/pari

USES=		compiler:c++11-lang gmake libtool localbase pkgconfig tar:xz
USE_LDCONFIG=	yes

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
