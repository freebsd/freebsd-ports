PORTNAME=	shim
PORTVERSION=	0.9
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	UEFI Secure Boot shim loader
WWW=		https://github.com/mjg59/shim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

DEPRECATED=			upstream has been inactive for 10 years and does not build with GCC 14
EXPIRATION_DATE=	2025-02-22

BUILD_DEPENDS=	${LOCALBASE}/lib/libgnuefi.a:devel/gnu-efi \
		bash:shells/bash

USES=		compiler gmake shebangfix
USE_CSTD=	gnu99
USE_GCC=	13

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
