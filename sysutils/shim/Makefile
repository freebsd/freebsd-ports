# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shim
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	UEFI Secure Boot shim loader

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${LOCALBASE}/lib/libgnuefi.a:devel/gnu-efi \
		bash:shells/bash

USES=		compiler gmake shebangfix
USE_CSTD=	gnu89
USE_GCC=	yes

SHEBANG_FILES=	make-certs

USE_GITHUB=	yes
GH_ACCOUNT=	mjg59

MAKE_ARGS=	CC="${CC} ${CFLAGS:M-std=*}" LD="${LD}" OBJCOPY="${OBJCOPY}"
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	lib/shim/shim.pem lib/shim/shim.key \
		lib/shim/MokManager.efi lib/shim/fallback.efi lib/shim/shim.efi

do-install:
	# Note that before this step, the shim.pem contains the _private_ key.
	openssl x509 -inform der -in ${WRKSRC}/shim.cer -outform pem -out ${WRKSRC}/shim.pem
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/shim
	${INSTALL_DATA} -m 600 ${WRKSRC}/shim.key ${STAGEDIR}${PREFIX}/lib/shim
.for file in shim.pem MokManager.efi fallback.efi shim.efi
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/lib/shim
.endfor

.include <bsd.port.mk>
