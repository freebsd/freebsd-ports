PORTNAME=	seabios
PORTVERSION=	1.16.0
PORTREVISION=	0
CATEGORIES=	misc
MASTER_SITES=	https://www.seabios.org/downloads/

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Open source implementation of a 16bit X86 BIOS
WWW=		http://www.seabios.org

LICENSE=	LGPL3

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to x86

USES=	gmake python:build

MAKE_ARGS=	AS="${AS}" HOSTCC="${CC}" LD="${LD}" OBJCPY="${OBJCPY}" \
		OBJDUMP="${OBJDUMP}" PYTHON="${PYTHON_CMD}"
NO_ARCH=	yes
USE_GCC=	yes:build
USE_BINUTILS=	yes

PLIST_FILES=	${DATADIR}/bios.bin

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/out/bios.bin ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
