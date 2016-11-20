# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shim
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UEFI Secure Boot shim loader

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libgnuefi.a:devel/gnu-efi \
		bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	mjg59

USES=		gmake
USE_GCC=	yes
USE_GITHUB=	yes
MAKE_JOBS_UNSAFE=	yes
ONLY_FOR_ARCHS=	amd64

PLIST_FILES=	lib/shim/shim.pem lib/shim/shim.key \
		lib/shim/MokManager.efi lib/shim/fallback.efi lib/shim/shim.efi

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" ${WRKSRC}/make-certs
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' ${WRKSRC}/Makefile

do-install:
	# Note that before this step, the shim.pem contains the _private_ key.
	openssl x509 -inform der -in ${WRKSRC}/shim.cer -outform pem -out ${WRKSRC}/shim.pem
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/shim
	${INSTALL_DATA} -m 600 ${WRKSRC}/shim.key ${STAGEDIR}/${PREFIX}/lib/shim
	${INSTALL_DATA} ${WRKSRC}/shim.pem ${STAGEDIR}/${PREFIX}/lib/shim
	${INSTALL_DATA} ${WRKSRC}/shim.efi ${STAGEDIR}/${PREFIX}/lib/shim
	${INSTALL_DATA} ${WRKSRC}/MokManager.efi ${STAGEDIR}/${PREFIX}/lib/shim
	${INSTALL_DATA} ${WRKSRC}/fallback.efi ${STAGEDIR}/${PREFIX}/lib/shim

.include <bsd.port.mk>
