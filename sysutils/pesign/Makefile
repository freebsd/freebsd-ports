# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>

PORTNAME=	pesign
PORTVERSION=	0.110
PORTREVISION=	8
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b535d1ac5cbc.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Signing utility for UEFI secure boot

LICENSE=	GPLv2

DEPRECATED=	Unmaintaned since 2016, very much out of date, does not build with GCC 11 (PR \#263544)
EXPIRATION_DATE=	2022-07-01

LIB_DEPENDS=	libefivar.so.0:devel/efivar \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libpopt.so:devel/popt \
		libuuid.so:misc/e2fsprogs-libuuid

USE_GCC=	10
USE_GITHUB=	yes
GH_ACCOUNT=	rhinstaller

USES=		gmake localbase pkgconfig
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=		aarch64 armv6 armv7 amd64 i386
ONLY_FOR_ARCHS_REASON=	UEFI specification only supports little-endian processors

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
