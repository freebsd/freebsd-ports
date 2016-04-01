# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	crlibm
DISTVERSION=	1.0beta4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://lipforge.ens-lyon.fr/frs/download.php/%SUBDIR%/:1,2,3 \
		LOCAL/bf/crlibm:4
MASTER_SITE_SUBDIR=	162/:1 153/:2 154/:3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1,4
DIST_SUBDIR=	crlibm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Correctly-rounded mathematics library

LICENSE=	LGPL21

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
OPTIONS_DEFINE=	TEST DOCS
OPTIONS_DEFAULT=	TEST
TEST_DESC=	Include all test capabilities (requires MPFR)

.include <bsd.port.options.mk>
.if make(makesum) || ${PORT_OPTIONS:MDOCS}
DISTFILES+=	crlibm-1.0beta3.pdf:2,4 tripledoubleprocedures-1.0beta3.pdf:3,4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/\($$(AM_CFLAGS)\) \($$(CFLAGS)\)/\2 \1/' \
		${WRKSRC}/tests/Makefile.in

.if !empty(MACHINE_CPU:Msse2)
CFLAGS+=		-msse2 -mfpmath=sse
CONFIGURE_ARGS+=	--enable-sse2
.endif

.if ${PORT_OPTIONS:MTEST}
CONFIGURE_ARGS+=	--enable-mpfr
LIB_DEPENDS+=		libmpfr.so:math/mpfr
.else
CONFIGURE_ARGS+=	--disable-mpfr
.endif

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} check

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	${DISTFILES:C|\:.*||:M*.pdf}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.endif

.include <bsd.port.mk>
