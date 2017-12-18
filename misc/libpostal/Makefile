# $FreeBSD$

PORTNAME=	libpostal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	misc geography

MAINTAINER=	dg@syrec.org
COMMENT=	Library for parsing/normalizing street addresses around the world

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl

USES=		autoreconf libtool localbase
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--datadir=${LIBPOSTAL_DATADIR} \
		--disable-data-download
USE_GITHUB=	yes
GH_ACCOUNT=	openvenues
TEST_TARGET=	check

LIBPOSTAL_DATADIR?=	/var/db/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		LIBPOSTAL_DATADIR=${LIBPOSTAL_DATADIR}

PORTDOCS=	README.md

OPTIONS_DEFINE=	CBLAS DOCS SSE2 STATIC
CBLAS_DESC=	Build with CBLAS/OPENBLAS
SSE2_DESC=	Enable SSE2 optimization
OPTIONS_SUB=	yes

CBLAS_BUILD_DEPENDS=	${LOCALBASE}/include/cblas.h:math/cblas
CBLAS_LIB_DEPENDS=	libopenblas.so:math/openblas
CBLAS_CONFIGURE_WITH=	cblas=${LOCALBASE}/lib/libopenblas.so

SSE2_CONFIGURE_ENABLE=	sse2

STATIC_CONFIGURE_ENABLE=	static

pre-configure:
	@cd ${WRKSRC} && ${SH} bootstrap.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpostal.so
	${INSTALL_PROGRAM} ${WRKSRC}/src/address_parser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/libpostal ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
