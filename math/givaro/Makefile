# $FreeBSD$

PORTNAME=	givaro
PORTVERSION=	3.8.0
CATEGORIES=	math
MASTER_SITES=	https://forge.imag.fr/frs/download.php/592/ LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for computer algebra

LICENSE=	CeCILL-Bv1-en.txt
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] B license, version 1
LICENSE_FILE=	${WRKSRC}/Licence_CeCILL-B_V1-en.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		libtool localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp="${LOCALBASE}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ON=	--enable-doc --with-docdir=${DOCSDIR}

post-patch:
	@${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/{s/-O2 //;s/-pipe//;}' \
		-e '/DEBUG_CFLAGS=.*-DNDEBUG/s/$${DEBUG_CFLAGS} //' \
		-e '/^WARN_CFLAGS="-Wall"/d' \
		-e '/if test "x$$WARN" = "xyes"/s/$$/ WARN_CFLAGS="-Wall" ;/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/sed -i/& ""/' ${WRKSRC}/docs/Makefile.in

post-install-DOXYGEN-on:
	@${RMDIR} ${STAGEDIR}${DOCSDIR}/givaro-dev-html
	@${FIND} ${WRKSRC}/docs/givaro-html -not -type d \
		| ${SED} -ne 's,^${WRKSRC}/docs/givaro-html,${DOCSDIR}/givaro-html,p' >> ${TMPPLIST}

.include <bsd.port.mk>
