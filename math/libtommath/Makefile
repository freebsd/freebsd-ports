# $FreeBSD$

PORTNAME=	libtommath
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/libtom/libtommath/releases/download/v${PORTVERSION}/
DISTNAME=	ltm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake tar:xz
ALL_TARGET=	default
CFLAGS+=	-fPIC
PORTDOCS=	*

PLIST_FILES=	include/tommath.h include/tommath_class.h \
		include/tommath_superclass.h lib/libtommath.a

OPTIONS_DEFINE=	DOCS SHARED

SHARED_DESC=	Build shared library
SHARED_USES=		libtool:build
SHARED_USE=		LDCONFIG=yes
SHARED_PLIST_FILES=	lib/libtommath.so lib/libtommath.so.1 lib/libtommath.so.1.0.0
SHARED_VARS=		MAKEFILE=makefile.shared
SHARED_VARS_OFF=	MAKEFILE=makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${STAGEDIR}${DOCSDIR}

post-install-SHARED-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtommath.so.1

do-test:
	(cd ${WRKSRC}; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f ${MAKEFILE} mtest test; \
	 ./mtest/mtest | ./test)

.include <bsd.port.mk>
