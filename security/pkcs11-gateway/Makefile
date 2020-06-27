# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkcs11-gateway
PORTVERSION=	1.4
CATEGORIES=	security devel linux
MASTER_SITES=	LOCAL/ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Wrapper Cryptoki library to use Linux PKCS\#11 modules

LICENSE=	LGPL20

USES=		linux

OPTIONS_DEFINE=	DOCS

USE_LDCONFIG=	yes
USE_LINUX=	base:run devtools:build

.include <bsd.port.pre.mk>

PKCS11_BINS=	pkcs11-gateway32
.if ${ARCH} == "amd64"
PKCS11_BINS+=	pkcs11-gateway64
.endif

PKCS11_LIB=	libpkcs11-gateway.so

PLIST_FILES=	${PKCS11_BINS:S,^,bin/,} \
		${PKCS11_LIB:S,^,lib/,}

PORTDOCS=	README

do-build:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.Linuxulator ${PKCS11_BINS})
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.FreeBSD ${PKCS11_LIB})

do-install:
.for b in ${PKCS11_BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${b} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${INSTALL_LIB} ${WRKSRC}/libpkcs11-gateway.so ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
