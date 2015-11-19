# $FreeBSD$

PORTNAME=	libtommath
PORTVERSION=	0.42.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://libtom.net/files/
DISTNAME=	ltm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake tar:bzip2
ALL_TARGET=	default
CFLAGS+=	-fPIC
PORTDOCS=	*

PLIST_FILES=	include/tommath.h include/tommath_class.h \
		include/tommath_superclass.h lib/libtommath.a

OPTIONS_DEFINE=	DOCS SHARED

SHARED_DESC=	Build shared library
SHARED_USES=		libtool:build
SHARED_USE=		LDCONFIG=yes
SHARED_PLIST_FILES=	lib/libtommath.so lib/libtommath.so.0 lib/libtommath.so.0.0.41
SHARED_VARS=		MAKEFILE=makefile.shared
SHARED_VARS_OFF=	MAKEFILE=makefile

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/makefile.shared
	${REINPLACE_CMD} -e 's|DESTDIR=|DESTDIR?=| ; s|-g $$(GROUP) -o $$(USER)||' ${WRKSRC}/${MAKEFILE}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${STAGEDIR}${DOCSDIR}

post-install-SHARED-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtommath.so.0

regression-test:
	(cd ${WRKSRC}; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f ${MAKEFILE} mtest test; \
	 ./mtest/mtest | ./test)

.include <bsd.port.mk>
