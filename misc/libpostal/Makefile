# $FreeBSD$

PORTNAME=	libpostal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
DISTVERSIONSUFFIX=	-alpha
PORTREVISION=	2
CATEGORIES=	misc geography

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	21601eb4b8941b8d6d9b795b1d6db4bd376f5b28.patch:-p1

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Library for parsing/normalizing street addresses around the world

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to compile: tagger.h:5: redefinition of typedef 'tagger_feature_function'
BROKEN_mips64=		fails to compile: tagger.h:5: redefinition of typedef 'tagger_feature_function'

RUN_DEPENDS=	curl:ftp/curl

USES=		autoreconf libtool localbase

USE_GITHUB=	yes
GH_ACCOUNT=	openvenues

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${LIBPOSTAL_DATADIR} \
		--disable-data-download \
		--disable-static
TEST_TARGET=	check

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		LIBPOSTAL_DATADIR=${LIBPOSTAL_DATADIR}

PORTDOCS=	README.md


OPTIONS_DEFINE=	CBLAS DOCS SSE2
OPTIONS_SUB=	yes

CBLAS_DESC=	Build with CBLAS/OPENBLAS
SSE2_DESC=	Enable SSE2 optimization

CBLAS_LIB_DEPENDS=	libopenblas.so:math/openblas
CBLAS_CONFIGURE_WITH=	cblas=${LOCALBASE}/lib/libopenblas.so

SSE2_CONFIGURE_ENABLE=	sse2

LIBPOSTAL_DATADIR?=	/var/db/${PORTNAME}

pre-configure:
	@cd ${WRKSRC} && ${SH} bootstrap.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpostal.so
	${INSTALL_SCRIPT} ${WRKSRC}/src/address_parser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/libpostal ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
