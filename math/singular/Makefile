# $FreeBSD$

PORTNAME=	singular
DISTVERSION=	4.1.2-586
DISTVERSIONSUFFIX=	-gfda4c85aa
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer algebra system for polynomial computations

LICENSE=	GPLv3RLE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool ncurses perl5 pkgconfig readline shebangfix
GNU_CONFIGURE=	yes
USE_GITHUB=	build
GH_ACCOUNT=	Singular
GH_PROJECT=	Sources
USE_PERL5=	build
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} --disable-dependency-tracking --without-python
MAKE_JOBS_UNSAFE=	yes
SHEBANG_FILES=	Singular/surfex \
		libpolys/libpolys-config.in \
		libsingular-config.in

# not a shebang but "/bin/bash" is hardcoded in some files
post-patch:
	  @${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g" \
		 ${WRKSRC}/emacs/.emacs-general

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
