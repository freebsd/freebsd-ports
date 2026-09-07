PORTNAME=	gost-engine
DISTVERSION=	g20250528
CATEGORIES=	security

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Implementation of the Russian GOST crypto algorithms for OpenSSL
WWW=		https://github.com/gost-engine/engine/blob/master/README.gost

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	base openssl30

USES=		cmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	gost-engine
GH_PROJECT=	engine

openssl30_PKGNAMESUFFIX=	-${FLAVOR}

BROKEN_SSL=				libressl libressl-devel openssl34 openssl35 openssl36
BROKEN_SSL_REASON_libressl=		needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_libressl-devel=	needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_openssl34=		not ready for openssl34
BROKEN_SSL_REASON_openssl35=		not ready for openssl35
BROKEN_SSL_REASON_openssl36=		not ready for openssl36

ENGINESDIR?=	${PREFIX}/${EDIR}
PLIST_SUB+=	EDIR="${EDIR}"

CMAKE_ARGS+=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DOPENSSL_ENGINES_DIR=${ENGINESDIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == openssl
.if !defined(FLAVOR)
FLAVOR=		openssl30
PKGNAMEPREFIX=	a-
.endif
.endif

.if ${FLAVOR:U} == openssl30
EDIR?=		lib/engines-12
BROKEN_SSL+=	base
.else
EDIR?=		lib/engines-3
.endif

GH_TAGNAME=	806d9ee
GH_TUPLE+=	provider-corner:libprov:d5d381f:libprov
GH_SUBDIR=	libprov:libprov

post-patch:
	${REINPLACE_CMD} \
	    's|/usr/lib/ssl/engines/libgost.so|${PREFIX}/${EDIR}/gost.so|' \
	    ${WRKSRC}/INSTALL.md

post-install-DOCS-off:
	cd ${STAGEDIR}${PREFIX}/share/man/man1 && ${RM} gost12sum.1 gostsum.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} INSTALL.md README.gost README.md \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${FILESDIR}/openssl.cnf.diff ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
