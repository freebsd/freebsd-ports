# $FreeBSD$

PORTNAME=	singular
PORTVERSION=	4.1.3
CATEGORIES=	math
MASTER_SITES=	ftp://jim.mathematik.uni-kl.de/pub/Math/Singular/SOURCES/${PORTVERSION:C/\./-/g}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer algebra system for polynomial computations

LICENSE=	GPLv3RLE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool ncurses perl5 pkgconfig readline shebangfix
GNU_CONFIGURE=	yes
#USE_GITHUB=	build
#GH_ACCOUNT=	Singular
#GH_PROJECT=	Sources
USE_PERL5=	build
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} --disable-dependency-tracking --without-python
MAKE_JOBS_UNSAFE=	yes
SHEBANG_FILES=	Singular/surfex \
		libpolys/libpolys-config.in \
		libsingular-config.in

OPTIONS_DEFINE=		NTL
OPTIONS_DEFAULT=	NTL
OPTIONS_SUB=		yes
NTL_DESC=		Use NTL library
NTL_LIB_DEPENDS=	libntl.so:math/ntl	\
			libcddgmp.so:math/cddlib
NTL_CONFIGURE_ON=	--with-ntl=${LOCALBASE} --with-flint=no
NTL_CONFIGURE_OFF=	--with-ntl=no
NTL_USES=		compiler:c11

# not a shebang but "/bin/bash" is hardcoded in some files
post-patch:
	  @${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g" \
		 ${WRKSRC}/emacs/.emacs-general

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
