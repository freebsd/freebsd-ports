# Created by: ijliao
# $FreeBSD$

PORTNAME=	fityk
PORTVERSION=	0.9.8
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/xylib:xylib
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${XYLIB_DISTNAME}${EXTRACT_SUFX}:xylib

MAINTAINER=	sperber@FreeBSD.org
COMMENT=	Free peak fitting software

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/include/classic_core.hpp:${PORTSDIR}/devel/boost-libs \
		gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USES=		desktop-file-utils gmake libtool shared-mime-info tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LDFLAGS+=	-lbz2 -lz
USE_GITHUB=	yes
GH_ACCOUNT=	wojdyr
USE_GNOME=	gtk20
USE_WX=		3.0
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-doc --disable-xyconvert
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

CFLAGS+=	-D_GNU_SOURCE
CPPFLAGS+=	-I${WRKDIR}/${XYLIB_DISTNAME} \
		-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${WRKDIR}/${XYLIB_DISTNAME}/xylib/.libs \
		-L${LOCALBASE}/lib ${PTHREAD_LIBS}

XYLIB_DISTNAME=	xylib-1.1

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/HELP_DEF/s|pkgdatadir|docdir|g' \
		${WRKSRC}/src/wxgui/Makefile.in
	@${REINPLACE_CMD} -e '/XYLIB_USE_TR1_MEMORY/s| 1| 0|g' \
		${WRKDIR}/${XYLIB_DISTNAME}/xylib/cache.h

pre-configure:
	@cd ${WRKDIR}/${XYLIB_DISTNAME} \
		&& ${SH} ./configure --disable-shared \
			CC="${CC}" CFLAGS="${CFLAGS} -fPIC" \
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -fPIC" \
			CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

pre-build:
	@cd ${WRKDIR}/${XYLIB_DISTNAME} \
		&& ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
			${ALL_TARGET}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fityk.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKDIR}/${XYLIB_DISTNAME}/xyconv ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${XYLIB_DISTNAME}/xyconv.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
