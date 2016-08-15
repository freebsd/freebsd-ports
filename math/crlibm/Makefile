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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Correctly-rounded mathematics library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		localbase
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PORTDOCS=	${DISTFILES:C|\:.*||:M*.pdf}

OPTIONS_DEFINE=		EXTRA_TEST DOCS
OPTIONS_DEFAULT=	EXTRA_TEST

EXTRA_TEST_DESC=		Include all test capabilities (requires MPFR)
EXTRA_TEST_LIB_DEPENDS=		libmpfr.so:math/mpfr \
				libgmp.so:math/gmp
EXTRA_TEST_CONFIGURE_ENABLE=	mpfr

.include <bsd.port.options.mk>

.if make(makesum) || ${PORT_OPTIONS:MDOCS}
DISTFILES+=		crlibm-1.0beta3.pdf:2,4 tripledoubleprocedures-1.0beta3.pdf:3,4
.endif

.if !empty(MACHINE_CPU:Msse2)
CFLAGS+=		-msse2 -mfpmath=sse
CONFIGURE_ARGS+=	--enable-sse2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/\($$(AM_CFLAGS)\) \($$(CFLAGS)\)/\2 \1/' \
		${WRKSRC}/tests/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${_DISTDIR} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
