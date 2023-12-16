PORTNAME=	gmp-ecm
DISTVERSION=	7.0.5
CATEGORIES=	math
MASTER_SITES=	https://gitlab.inria.fr/zimmerma/ecm/uploads/${GL_TAG}/
DISTNAME=	ecm-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Elliptic Curve Method for Integer Factorization
WWW=		https://gforge.inria.fr/projects/ecm/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake libtool

GL_TAG=		89f6f0d65d3e980cef33dc922004e4b2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_XSLTPROC=no \
		--with-gmp=${LOCALBASE} \
		--enable-shared \
		--disable-static
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_FILES=	bin/ecm include/ecm.h \
		lib/libecm.so \
		lib/libecm.so.1 \
		lib/libecm.so.1.0.0 \
		man/man1/ecm.1.gz

.include <bsd.port.mk>
