# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkcs11-gateway
PORTVERSION=	1.2
CATEGORIES=	security devel linux
MASTER_SITES=	LOCAL/ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Wrapper Cryptoki library to use Linux PKCS\#11 modules

LICENSE=	LGPL20

MAKEFILE=	Makefile.FreeBSD
USE_LDCONFIG=	yes
USES=		linux

PLIST_FILES=	bin/pkcs11-gateway lib/libpkcs11-gateway.so \
		lib/libpkcs11-gateway.so.1

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkcs11-gateway ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libpkcs11-gateway.so.1 ${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libpkcs11-gateway.so.1 \
		libpkcs11-gateway.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
