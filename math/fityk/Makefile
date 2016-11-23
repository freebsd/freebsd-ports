# Created by: ijliao
# $FreeBSD$

PORTNAME=	fityk
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free peak fitting software

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>=1.35:devel/boost-libs \
		swig2.0:devel/swig20 \
		gnuplot:math/gnuplot
RUN_DEPENDS=	gnuplot:math/gnuplot

USE_GITHUB=	yes
GH_ACCOUNT=	wojdyr
GH_PROJECT=	xylib:xylib
GH_TAGNAME=	v1.4:xylib

USES=		autoreconf compiler:c++11-lib desktop-file-utils gmake \
		libtool lua readline shared-mime-info
USE_CXXSTD=	c++11
USE_GNOME=	gtk20
USE_WX=		3.0
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-D_GNU_SOURCE
CPPFLAGS+=	-I${WRKDIR}/xylib-1.4 \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${WRKDIR}/xylib-1.4/xylib/.libs \
		-lpthread -lbz2 -lz -L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
PYTHON_USES=		python
PYTHON_CONFIGURE_ENABLE=	python

post-patch:
	@${REINPLACE_CMD} -e '/)\/html/s|^|#|' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/doc/fityk.1
	@${REINPLACE_CMD} -e '/XYLIB_USE_TR1_MEMORY/s| 1| 0|' \
		${WRKDIR}/xylib-1.4/xylib/cache.h

pre-configure:
	@cd ${WRKDIR}/xylib-1.4 \
		&& ${AUTORECONF} -f -i \
		&& ${SH} ./configure --disable-shared --without-gui \
			CC="${CC}" CFLAGS="${CFLAGS} -fPIC" \
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -fPIC" \
			CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

pre-build:
	@cd ${WRKDIR}/xylib-1.4 && ${DO_MAKE_BUILD} ${ALL_TARGET}

post-build-DOCS-on:
	@cd ${WRKSRC}/doc && ${DO_MAKE_BUILD} html

post-install:
	(cd ${WRKDIR}/xylib-1.4 && ${INSTALL_PROGRAM} xyconv \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKDIR}/xylib-1.4 && ${INSTALL_MAN} xyconv.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html \
		${STAGEDIR}${DOCSDIR})
	@${LN} -sf ${DOCSDIR}/html ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
