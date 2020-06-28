# Created by: Eugene Grosbein <eugen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gost-engine
DISTVERSION=	g20190421
CATEGORIES=	security

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Implementation of the Russian GOST crypto algorithms for OpenSSL

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=			libressl libressl-devel
BROKEN_SSL_REASON_libressl=	needs features only available in OpenSSL 1.1.1+
BROKEN_SSL_REASON_libressl-devel=needs features only available in OpenSSL 1.1.1+

USES=		cmake ssl

ENGINESDIR?=	${PREFIX}/lib/engines-1.1

CMAKE_ARGS+=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DOPENSSL_ENGINES_DIR=${ENGINESDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	gost-engine
GH_PROJECT=	engine
GH_TAGNAME=	7ed64cd

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085
BROKEN_SSL+=			base
BROKEN_SSL_REASON_base=		needs features only available in OpenSSL 1.1.1+
.endif

post-patch:
	${REINPLACE_CMD} 's/-Werror //' ${WRKSRC}/CMakeLists.txt

post-install:
	( cd ${STAGEDIR}${PREFIX}/lib/engines-1.1 && ${MV} gost.so libgost.so )

post-install-DOCS-off:
	( cd ${STAGEDIR}${PREFIX}/man/man1 && ${RM} gost12sum.1 gostsum.1 )

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKSRC} && ${INSTALL_MAN} INSTALL.md README.gost README.md \
		${STAGEDIR}${DOCSDIR} )

.include <bsd.port.mk>
