PORTNAME=	gost-engine
CATEGORIES=	security

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Implementation of the Russian GOST crypto algorithms for OpenSSL
WWW=		https://github.com/gost-engine/engine/blob/master/README.gost

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	base openssl30

openssl30_PKGNAMESUFFIX=	-${FLAVOR}
openssl30_PLIST=	${.CURDIR}/pkg-plist-${FLAVOR}

BROKEN_SSL=				libressl libressl-devel openssl31
BROKEN_SSL_REASON_libressl=		needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_libressl-devel=	needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_openssl31=		not ready for openssl31

BUILD_DEPENDS=  cmake>=3.18.1:devel/cmake

USES=		cmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=     gost-engine
GH_PROJECT=     engine

BASE_OPENSSL_VSTR!= /usr/bin/openssl version
BASE_OPENSSL_VER=${BASE_OPENSSL_VSTR:C/^OpenSSL //W:C/\..*//gW}

.if ${FLAVOR:U} == openssl30 || ${BASE_OPENSSL_VER:U} == 3
GH_TAGNAME=     2b22503
GH_TUPLE+=      provider-corner:libprov:e9f3e6a:libprov
GH_SUBDIR=      libprov:libprov
DISTVERSION=	g20230106
EDIR?=		lib/engines-12
EDIRV?=		@comment unused
DISTINFO_FILE=	${.CURDIR}/distinfo.openssl30
.if ${BASE_OPENSSL_VER:U} != 3
BROKEN_SSL+=	base # openssl31
.endif
.else
GH_TAGNAME=	739f957
DISTVERSION=	g20220520
BROKEN_SSL+=	openssl30 # openssl31
EDIR?=		lib/engines-1.1
EDIRV?=		${EDIR}
.endif

ENGINESDIR?=	${PREFIX}/${EDIR}
PLIST_SUB+=     EDIR="${EDIR}" EDIRV="${EDIRV}"

CMAKE_ARGS+=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DOPENSSL_ENGINES_DIR=${ENGINESDIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == openssl30
FLAVOR=	openssl30
.endif

.if ${FLAVOR:U} == base
post-patch:
	${REINPLACE_CMD} 's/-Werror //' ${WRKSRC}/CMakeLists.txt

post-install:
	cd ${STAGEDIR}${PREFIX}/lib/engines-1.1 && \
	  ${MV} gost.so.1.1 libgost.so.1.1 && ${LN} -s libgost.so.1.1 libgost.so && \
	  ${RM} gost.so
.endif

post-install-DOCS-off:
	cd ${STAGEDIR}${PREFIX}/share/man/man1 && ${RM} gost12sum.1 gostsum.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} INSTALL.md README.gost README.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
