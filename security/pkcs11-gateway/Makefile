# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkcs11-gateway
PORTVERSION=	1.2
CATEGORIES=	security devel linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A wrapper Cryptoki library to use Linux PKCS\#11 modules

LICENSE=	LGPL20

MAKEFILE=	Makefile.FreeBSD
USE_LDCONFIG=	yes
USE_LINUX=	yes

PLIST_FILES=	bin/pkcs11-gateway lib/libpkcs11-gateway.so \
		lib/libpkcs11-gateway.so.1

PORTDOCS=	README

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkcs11-gateway ${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libpkcs11-gateway.so.1 ${PREFIX}/lib/
	cd ${PREFIX}/lib && ${LN} -sf libpkcs11-gateway.so.1 \
		libpkcs11-gateway.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
