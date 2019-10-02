# $FreeBSD$

PORTNAME=	singular
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.mathematik.uni-kl.de/ftp/pub/Math/Singular/SOURCES/4-1-1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computer algebra system for polynomial computations

LICENSE=	GPLv3RLE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		gmake libtool ncurses perl5 pkgconfig shebangfix
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes
SHEBANG_FILES=	libpolys/libpolys-config.in \
		libsingular-config.in

# not a shebang but "/bin/bash" is hardcoded in some files
post-patch:
	  @${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g" \
		 ${WRKSRC}/emacs/.emacs-general


.include <bsd.port.mk>
