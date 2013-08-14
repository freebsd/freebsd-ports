# $FreeBSD$

PORTNAME=	libtommath
PORTVERSION=	0.42.0
CATEGORIES=	math
MASTER_SITES=	http://libtom.org/files/
DISTNAME=	ltm-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines

OPTIONS_DEFINE=	DOCS SHARED
SHARED_DESC=	Build shared library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
CFLAGS+=	-fPIC
PORTDOCS=	*

PLIST_FILES=	include/tommath.h include/tommath_class.h \
		include/tommath_superclass.h lib/libtommath.a

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/makefile.shared

.if ${PORT_OPTIONS:MSHARED}
BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool
USE_LDCONFIG=	yes
PLIST_FILES+=	lib/libtommath.la lib/libtommath.so.0 lib/libtommath.so
MAKEFILE=	makefile.shared
.else
MAKEFILE=	makefile
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${DOCSDIR}/
.endif

#regression-test:
#	(cd ${WRKSRC}; \
#	 ${SETENV} ${MAKE_ENV} ${GMAKE} -f ${MAKEFILE} mtest test; \
#	 ./mtest/mtest | ./test)

.include <bsd.port.mk>
