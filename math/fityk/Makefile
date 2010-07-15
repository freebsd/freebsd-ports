# ex:ts=8
# Ports collection makefile for:	fityk
# Date created:			Mar 8, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fityk
PORTVERSION=	0.9.2
CATEGORIES=	math
MASTER_SITES=	SF \
		SF/xylib:xylib
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${XYLIB_DISTNAME}${EXTRACT_SUFX}:xylib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free peak fitting software

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/core.hpp:${PORTSDIR}/devel/boost-libs \
		gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_WX=		2.8+
WX_CONF_ARGS=	absolute
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--without-doc --disable-xyconvert
USE_LDCONFIG=	yes

MAN1=		fityk.1 xyconv.1
PORTDOCS=	*

CFLAGS+=	-D_GNU_SOURCE
CPPFLAGS=	-I${WRKDIR}/${XYLIB_DISTNAME} \
		-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${WRKDIR}/${XYLIB_DISTNAME}/xylib/.libs \
		-L${LOCALBASE}/lib ${PTHREAD_LIBS}

XYLIB_DISTNAME=	xylib-0.6

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
	${INSTALL_MAN} ${WRKSRC}/doc/fityk.1 ${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKDIR}/${XYLIB_DISTNAME}/xyconv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${XYLIB_DISTNAME}/xyconv.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
