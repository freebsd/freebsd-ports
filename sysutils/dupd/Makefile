# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	dupd
PORTVERSION=	1.4
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	File duplicate detection CLI utility

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	jvirkki
GH_PROJECT=	libbloom:libbloom
GH_TAGNAME=	v1.4:libbloom

USES=	gmake ssl sqlite:3
LLD_UNSAFE=	yes
BINARY_ALIAS=	ld=ld.bfd

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

MAKE_ARGS=	LIB="-L${PREFIX}/lib" INC="-I${WRKSRC_libbloom} -I${PREFIX}/include" \
		LIBBLOOM_LIB="${WRKSRC_libbloom}/build" USAGE="${WRKSRC}/build/usage.o" \
		DIRENT_HAS_TYPE=1 GITHASH=c25a635e1d27ebf5759875a7ff907d8eec7f5be9

do-build:
	(cd ${WRKSRC_libbloom} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${WRKSRC_libbloom}/build/libbloom.a MM=-DGRR)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
