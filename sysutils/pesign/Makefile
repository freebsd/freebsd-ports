# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pesign
PORTVERSION=	0.110
CATEGORIES=	sysutils

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Signing utility for UEFI secure boot

LICENSE=	GPLv2

BROKEN=		Checksum and size mismatch

LIB_DEPENDS=	libefivar.so:${PORTSDIR}/devel/efivar \
		libnspr4.so:${PORTSDIR}/devel/nspr \
		libnss3.so:${PORTSDIR}/security/nss \
		libpopt.so:${PORTSDIR}/devel/popt \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GCC=	4.8+
USE_GITHUB=	yes
GH_ACCOUNT=	vathpela
GH_COMMIT=	00288b4

USES=		gmake pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1001505
BROKEN=		This port requires ppoll(2) system call
.endif

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

.include <bsd.port.post.mk>
