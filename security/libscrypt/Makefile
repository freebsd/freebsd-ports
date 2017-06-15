# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	libscrypt
PORTVERSION=	1.21
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	C library for the scrypt key derivation function

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	technion

MAKE_ARGS=	CC="${CC}" LIBDIR="${PREFIX}"/lib
TEST_TARGET=	check

PLIST_FILES=	include/libscrypt.h \
		lib/libscrypt.so \
		lib/libscrypt.so.0

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|?=-|+=-|; s|-O2 ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-fstack-protector ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|strcpy(mcf2, mcf);|strlcpy(mcf2, mcf, SCRYPT_MCF_LEN);|' \
			${WRKSRC}/main.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
