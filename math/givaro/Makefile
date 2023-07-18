PORTNAME=	givaro
PORTVERSION=	4.1.1
DISTVERSIONPREFIX=v
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	pi@FreeBSD.org
COMMENT=	C++ library for computer algebra
WWW=		https://casys.gricad-pages.univ-grenoble-alpes.fr/givaro

LICENSE=	CeCILL-Bv1-en.txt
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] B license, version 1
LICENSE_FILE=	${WRKSRC}/Licence_CeCILL-B_V1-en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf compiler:c++11-lang gmake libtool pathfix pkgconfig
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	linbox-team
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp="${LOCALBASE}"

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOCS_USE=		TEX=base:build,dvipsk:build,latex:build,pdftex:build
DOCS_CONFIGURE_ON=	--enable-doc --with-docdir=${DOCSDIR}

post-install-DOCS-on:
	${RMDIR} ${STAGEDIR}${DOCSDIR}/givaro-dev-html
	${FIND} ${WRKSRC}/docs/givaro-html -not -type d \
		| ${SED} -ne 's,^${WRKSRC}/docs/givaro-html,${DOCSDIR}/givaro-html,p' >> ${TMPPLIST}

.include <bsd.port.mk>
