# $FreeBSD$

PORTNAME=	libtommath
PORTVERSION=	0.42.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://libtom.org/files/
DISTNAME=	ltm-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines

OPTIONS_DEFINE=	DOCS SHARED
SHARED_DESC=	Build shared library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake tar:bzip2
ALL_TARGET=	default
CFLAGS+=	-fPIC
PORTDOCS=	*

PLIST_FILES=	include/tommath.h include/tommath_class.h \
		include/tommath_superclass.h lib/libtommath.a

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/makefile.shared
	${REINPLACE_CMD} -e 's|DESTDIR=|DESTDIR?=|' ${WRKSRC}/${MAKEFILE}

.if ${PORT_OPTIONS:MSHARED}
USES+=		libtool:build
USE_LDCONFIG=	yes
PLIST_FILES+=	lib/libtommath.so.0 lib/libtommath.so
MAKEFILE=	makefile.shared
.else
MAKEFILE=	makefile
.endif

post-install:
.if ${PORT_OPTIONS:MSHARED}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtommath.so.0
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${STAGEDIR}${DOCSDIR}

regression-test:
	(cd ${WRKSRC}; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f ${MAKEFILE} mtest test; \
	 ./mtest/mtest | ./test)

.include <bsd.port.mk>
