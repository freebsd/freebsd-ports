PORTNAME=	gost-engine
DISTVERSION=	g20220520
CATEGORIES=	security

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Implementation of the Russian GOST crypto algorithms for OpenSSL
WWW=		https://github.com/gost-engine/engine/blob/master/README.gost

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=				libressl libressl-devel openssl30 openssl31
BROKEN_SSL_REASON_libressl=		needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_libressl-devel=	needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_openssl30=		for OpenSSL 1.1.1 only
BROKEN_SSL_REASON_openssl31=		for OpenSSL 1.1.1 only

BUILD_DEPENDS=  cmake>=3.18.1:devel/cmake

USES=		cmake ssl
USE_GITHUB=	yes
GH_PROJECT=	engine
GH_TAGNAME=	739f957

ENGINESDIR?=	${PREFIX}/lib/engines-1.1

CMAKE_ARGS+=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DOPENSSL_ENGINES_DIR=${ENGINESDIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} 's/-Werror //' ${WRKSRC}/CMakeLists.txt

post-install:
	cd ${STAGEDIR}${PREFIX}/lib/engines-1.1 && \
	  ${MV} gost.so.1.1 libgost.so.1.1 && ${LN} -s libgost.so.1.1 libgost.so && \
	  ${RM} gost.so

post-install-DOCS-off:
	( cd ${STAGEDIR}${PREFIX}/share/man/man1 && ${RM} gost12sum.1 gostsum.1 )

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKSRC} && ${INSTALL_MAN} INSTALL.md README.gost README.md \
		${STAGEDIR}${DOCSDIR} )

.include <bsd.port.mk>
