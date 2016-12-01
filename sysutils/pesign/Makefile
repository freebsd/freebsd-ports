# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pesign
PORTVERSION=	0.110
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Signing utility for UEFI secure boot

LICENSE=	GPLv2

LIB_DEPENDS=	libefivar.so:devel/efivar \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libpopt.so:devel/popt \
		libuuid.so:misc/e2fsprogs-libuuid

USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rhinstaller

USES=		gmake localbase pkgconfig
USE_LDCONFIG=	yes

EXTRA_PATCHES=	${EXTRA_PATCHES_${OPSYS}_${OSREL:R}}
EXTRA_PATCHES_FreeBSD_9=	${FILESDIR}/extra-patch-src_client.c

ONLY_FOR_ARCHS=		aarch64 armv6 amd64 i386
ONLY_FOR_ARCHS_REASON=	UEFI specification only supports little-endian processors
BROKEN_armv6=		fails to compile: error: EFI_VARIABLE_NON_VOLATILE redefined

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' ${WRKSRC}/Make.defaults

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/efikeygen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/pesign ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libdpe/libdpe.so ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libdpe
	${INSTALL_DATA} ${WRKSRC}/include/libdpe/pe.h ${STAGEDIR}${PREFIX}/include/libdpe
	${INSTALL_DATA} ${WRKSRC}/include/libdpe/libdpe.h ${STAGEDIR}${PREFIX}/include/libdpe
	${INSTALL_MAN} ${WRKSRC}/src/efikeygen.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/pesign-client.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/pesign.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
