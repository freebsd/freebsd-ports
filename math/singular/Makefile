PORTNAME=	singular
DISTVERSIONPREFIX=	Release-
DISTVERSION=	4-3-2
PORTREVISION=	2
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
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Singular
GH_PROJECT=	Singular

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} --enable-Singular --enable-factory	\
		--with-libparse --disable-dependency-tracking --without-python

SHEBANG_FILES=	Singular/surfex \
		libpolys/libpolys-config.in \
		libsingular-config.in

TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS FLINT GFAN NTL
OPTIONS_DEFAULT=	DOCS FLINT GFAN NTL
OPTIONS_SUB=		yes

DOCS_MASTER_SITES=	ftp://jim.mathematik.uni-kl.de/pub/Math/Singular/SOURCES/${PORTVERSION:C/\./-/g}/:doc
DOCS_DISTFILES=		doc.tbz2:doc
DOCS_INFO=		${PORTNAME}
PORTDOCS=		*

FLINT_DESC=		Use FLINT library
FLINT_CONFIGURE_ON=	--with-flint=${LOCALBASE}
FLINT_CONFIGURE_OFF=	--with-flint=no
FLINT_LIB_DEPENDS=	libflint.so:math/flint2

GFAN_DESC=		Build gfanlib library (bundled)
GFAN_CONFIGURE_ENABLE=	gfanlib
GFAN_BUILD_DEPENDS=	gfan_tropicalbasis:math/gfan

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

# Singular tarballs made using "make dist" (without --enable-doc-build)
# do not contain built documentation (from Sagemath).
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}	\
		${STAGEDIR}${DOCSDIR}
	(cd ${STAGEDIR}${DOCSDIR} && ${TAR} xfj ${_DISTDIR}/doc.tbz2)
	${MV} ${STAGEDIR}${DOCSDIR}/singular.info	\
		${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
