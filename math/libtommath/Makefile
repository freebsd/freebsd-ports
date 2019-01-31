# $FreeBSD$

PORTNAME=	libtommath
DISTVERSION=	1.1.0
PORTREVISION=	0
CATEGORIES=	math
MASTER_SITES=	https://github.com/libtom/libtommath/releases/download/v${DISTVERSION}/
DISTNAME=	ltm-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines

LICENSE=	PD WTFPL
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
USES=		gmake tar:xz
ALL_TARGET=	default
CFLAGS+=	-fPIC
PORTDOCS=	*

PLIST_FILES=	include/tommath.h \
		include/tommath_class.h \
		include/tommath_superclass.h \
		lib/libtommath.a

OPTIONS_DEFINE=	DOCS SHARED

SHARED_DESC=		Build shared library
SHARED_USES=		libtool:build
SHARED_USE=		LDCONFIG=yes
SHARED_PLIST_FILES=	lib/libtommath.so \
			lib/libtommath.so.${DISTVERSION:R:R} \
			lib/libtommath.so.${DISTVERSION} \
			libdata/pkgconfig/libtommath.pc
SHARED_VARS=		MAKEFILE=makefile.shared
SHARED_VARS_OFF=	MAKEFILE=makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bn.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/poster.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tommath.pdf ${STAGEDIR}${DOCSDIR}

post-install-SHARED-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtommath.so.${DISTVERSION}

do-test:
	(cd ${WRKSRC}; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f ${MAKEFILE} mtest/mtest test; \
	 ./mtest/mtest | ./test)

.include <bsd.port.mk>
