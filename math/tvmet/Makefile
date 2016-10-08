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

USES=		gmake tar:bzip2 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cxx=${CXX}

OPTIONS_DEFINE=	CPPUNIT DEBUG DOCS EXAMPLES

CPPUNIT_LIB_DEPENDS=		libcppunit.so:devel/cppunit
CPPUNIT_CONFIGURE_ON=		--with-cppunit-prefix=${LOCALBASE}
CPPUNIT_CONFIGURE_ENV_OFF=	ac_cv_path_CPPUNIT_CONFIG=no

DEBUG_CXXFLAGS=		-DTVMET_DEBUG
DEBUG_CXXFLAGS_OFF=	-DTVMET_OPTIMIZE

post-patch:
	@${REINPLACE_CMD} -e 's|= -O |= |g' ${WRKSRC}/doc/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ext in dox cc css h png
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.${ext} \
		${STAGEDIR}${DOCSDIR})
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ext in cc
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} *.${ext} \
		${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
