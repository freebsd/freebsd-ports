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
OPTIONS_DEFINE=	TEST
OPTIONS_DEFAULT=	TEST
TEST_DESC=	Include all test capabilities (requires MPFR)

NO_STAGE=	yes
.include <bsd.port.options.mk>
.if make(makesum) || ${PORT_OPTIONS:MDOCS}
DISTFILES+=	crlibm-1.0beta3.pdf:2,4 tripledoubleprocedures-1.0beta3.pdf:3,4
.endif

post-patch:
#7-STABLE has log2() in libm after r226457 on 17 Oct 2011, but
#there was no accompanying __FreeBSD_version bump
.if ${OSVERSION} < 802502 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900027)
	@${REINPLACE_CMD} \
	-e '/testfun_libm[[:blank:]]*=[[:blank:]]*log2;/s/log2/NULL/' \
		${WRKSRC}/tests/test_common.c
.endif
	@${REINPLACE_CMD} -e 's/\($$(AM_CFLAGS)\) \($$(CFLAGS)\)/\2 \1/' \
		${WRKSRC}/tests/Makefile.in

.if !empty(MACHINE_CPU:Msse2)
CFLAGS+=		-msse2 -mfpmath=sse
CONFIGURE_ARGS+=	--enable-sse2
.endif

.if ${PORT_OPTIONS:MTEST}
CONFIGURE_ARGS+=	--enable-mpfr
LIB_DEPENDS+=		mpfr.4:${PORTSDIR}/math/mpfr
.else
CONFIGURE_ARGS+=	--disable-mpfr
.endif

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} check

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	${DISTFILES:C|\:.*||:M*.pdf}

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.endif

.include <bsd.port.mk>
