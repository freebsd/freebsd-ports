PORTNAME=	singular
DISTVERSIONPREFIX=	Release-
DISTVERSION=	4-2-0
CATEGORIES=	math
#MASTER_SITES=	ftp://jim.mathematik.uni-kl.de/pub/Math/Singular/SOURCES/${PORTVERSION:C/\./-/g}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer algebra system for polynomial computations

LICENSE=	GPLv3RLE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool ncurses perl5 pkgconfig readline shebangfix
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Singular
GH_PROJECT=	Singular
USE_PERL5=	build
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} --disable-dependency-tracking --without-python
MAKE_JOBS_UNSAFE=	yes
SHEBANG_FILES=	Singular/surfex \
		libpolys/libpolys-config.in \
		libsingular-config.in

OPTIONS_DEFINE=		FLINT NTL
OPTIONS_DEFAULT=	FLINT NTL
OPTIONS_SUB=		yes

FLINT_DESC=		Use FLINT library
FLINT_CONFIGURE_ON=	--with-flint=${LOCALBASE}
FLINT_CONFIGURE_OFF=	--with-flint=no
FLINT_LIB_DEPENDS=	libflint.so:math/flint2

NTL_DESC=		Use NTL library
NTL_USES=		compiler:c11
NTL_CONFIGURE_ON=	--with-ntl=${LOCALBASE}
NTL_CONFIGURE_OFF=	--with-ntl=no
NTL_LIB_DEPENDS=	libntl.so:math/ntl	\
			libcddgmp.so:math/cddlib

# not a shebang but "/bin/bash" is hardcoded in some files
post-patch:
	  @${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g" \
		 ${WRKSRC}/emacs/.emacs-general

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
