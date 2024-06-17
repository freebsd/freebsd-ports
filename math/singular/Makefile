PORTNAME=	singular
DISTVERSIONPREFIX=	Release-
DISTVERSION=	4-4-0
CATEGORIES=	math
#MASTER_SITES=	ftp://jim.mathematik.uni-kl.de/pub/Math/Singular/SOURCES/${PORTVERSION:C/\./-/g}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer algebra system for polynomial computations
WWW=		https://www.singular.uni-kl.de/

LICENSE=	GPLv3RLE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool ncurses perl5 pkgconfig readline shebangfix
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	Singular
GH_PROJECT=	Singular
USE_LDCONFIG=	yes
USE_PERL5=	build

SHEBANG_FILES=	Singular/surfex \
		libpolys/libpolys-config.in \
		libsingular-config.in

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} --enable-Singular --enable-factory	\
		--with-libparse --disable-dependency-tracking --without-python

TEST_TARGET=	check

PORTDOCS=		*

OPTIONS_DEFINE=		DOCS FLINT GFAN NTL
OPTIONS_DEFAULT=	DOCS FLINT GFAN NTL
OPTIONS_SUB=		yes

FLINT_DESC=		Use FLINT library
GFAN_DESC=		Build gfanlib library (bundled)
NTL_DESC=		Use NTL library

DOCS_MASTER_SITES=	ftp://jim.mathematik.uni-kl.de/pub/Math/Singular/SOURCES/${PORTVERSION:C/\./-/g}/:doc
DOCS_DISTFILES=		doc.tbz2:doc
DOCS_INFO=		${PORTNAME}
FLINT_LIB_DEPENDS=	libflint.so:math/flint2
FLINT_CONFIGURE_ON=	--with-flint=${LOCALBASE}
FLINT_CONFIGURE_OFF=	--with-flint=no
GFAN_BUILD_DEPENDS=	gfan_tropicalbasis:math/gfan
GFAN_CONFIGURE_ENABLE=	gfanlib
NTL_LIB_DEPENDS=	libntl.so:math/ntl	\
			libcddgmp.so:math/cddlib
NTL_USES=		compiler:c11
NTL_CONFIGURE_ON=	--with-ntl=${LOCALBASE}
NTL_CONFIGURE_OFF=	--with-ntl=no

# not a shebang but "/bin/bash" is hardcoded in some files
post-patch:
	  @${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g" \
		 ${WRKSRC}/emacs/.emacs-general

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

# Singular tarballs made using "make dist" (without --enable-doc-build)
# do not contain built documentation (from Sagemath).
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}	\
		${STAGEDIR}${DOCSDIR}
	(cd ${STAGEDIR}${DOCSDIR} && ${TAR} xfj ${_DISTDIR}/doc.tbz2)
	${MV} ${STAGEDIR}${DOCSDIR}/singular.info	\
		${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
