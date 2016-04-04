# Created by: ijliao
# $FreeBSD$

PORTNAME=	tvmet
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/Tar.Gz_Bz2%20Archive/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny Vector and Matrix template library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	CPPUNIT DEBUG DOCS EXAMPLES

USES=		gmake tar:bzip2 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cxx=${CXX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCPPUNIT}
LIB_DEPENDS+=	libcppunit.so:devel/cppunit
CONFIGURE_ARGS+=	--with-cppunit-prefix=${LOCALBASE}
.else
CONFIGURE_ENV+=	ac_cv_path_CPPUNIT_CONFIG=no
.endif

.if ${PORT_OPTIONS:MDEBUG}
CXXFLAGS+=	-DTVMET_DEBUG
.else
CXXFLAGS+=	-DTVMET_OPTIMIZE
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= -O |= |g' ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ext in dox cc css h png
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.${ext} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ext in cc
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} *.${ext} \
		${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
