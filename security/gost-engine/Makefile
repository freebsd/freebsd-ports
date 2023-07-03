PORTNAME=	gost-engine
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Implementation of the Russian GOST crypto algorithms for OpenSSL
WWW=		https://github.com/gost-engine/engine/blob/master/README.gost

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	base openssl30

openssl30_PKGNAMESUFFIX=	-${FLAVOR}

BROKEN_SSL=				libressl libressl-devel openssl31
BROKEN_SSL_REASON_libressl=		needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_libressl-devel=	needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_openssl31=		not ready for openssl31

BUILD_DEPENDS=  cmake>=3.18.1:devel/cmake

USES=		cmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=     gost-engine
GH_PROJECT=     engine

ENGINESDIR?=	${PREFIX}/${EDIR}
PLIST_SUB+=     EDIR="${EDIR}"

CMAKE_ARGS+=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DOPENSSL_ENGINES_DIR=${ENGINESDIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == openssl30
FLAVOR=	openssl30
.endif

# For OpenSSL 3.0.x in base (14+) or installed as port/package
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 || ${FLAVOR:U} == openssl30
GH_TAGNAME=     2b22503
GH_TUPLE+=      provider-corner:libprov:e9f3e6a:libprov
GH_SUBDIR=      libprov:libprov
DISTVERSION=	g20230106
DISTINFO_FILE=	${PKGDIR}/distinfo.openssl30
PLIST=		${PKGDIR}/pkg-plist-openssl30

.if ${FLAVOR:U} == openssl30
EDIR?=		lib/engines-12
BROKEN_SSL+=	base
.else
EDIR?=		lib/engines-3
.endif

post-patch:
	${REINPLACE_CMD} \
	    's|/usr/lib/ssl/engines/libgost.so|${PREFIX}/${EDIR}/gost.so|' \
	    ${WRKSRC}/INSTALL.md

# For OpenSSL 1.1.x in base or installed as port/package
.else
GH_TAGNAME=	739f957
DISTVERSION=	g20220520
BROKEN_SSL+=	openssl30 # openssl31
EDIR?=		lib/engines-1.1

post-patch:
	${REINPLACE_CMD} 's/-Werror //' ${WRKSRC}/CMakeLists.txt

post-install:
	cd ${STAGEDIR}${PREFIX}/${EDIR} && \
	  ${MV} gost.so.1.1 libgost.so.1.1 && ${LN} -s libgost.so.1.1 libgost.so && \
	  ${RM} gost.so
.endif

post-install-DOCS-off:
	cd ${STAGEDIR}${PREFIX}/share/man/man1 && ${RM} gost12sum.1 gostsum.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} INSTALL.md README.gost README.md \
		${STAGEDIR}${DOCSDIR}
.if ${EDIR:M*engines-3}
	${INSTALL_MAN} ${FILESDIR}/openssl.cnf.diff ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
