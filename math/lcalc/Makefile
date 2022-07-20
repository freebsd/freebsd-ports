PORTNAME=	lcalc
PORTVERSION=	2.0.5
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/misc/sage/spkg/upstream/lcalc/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	L-function c++ class library and the CLI program lcalc

LICENSE=	GPLv2+

BUILD_DEPENDS=	gengetopt:devel/gengetopt
LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libpari.so:math/pari

#USE_GITHUB=	yes
#GH_ACCOUNT=	agrawroh
#GH_PROJECT=	l-calc
#GH_TAGNAME=	4c57471

USES=		compiler:c++11-lang gmake libtool localbase tar:xz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pari
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
.for dir in . data
	${REINPLACE_CMD} -e 's|@docdir@/examples|${EXAMPLESDIR}|'	\
		${WRKSRC}/doc/examples/${dir}/Makefile.in
.endfor

.include <bsd.port.mk>
