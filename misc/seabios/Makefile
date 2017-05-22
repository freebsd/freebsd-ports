# $FreeBSD$

PORTNAME=	seabios
PORTVERSION=	1.10.2
PORTREVISION=	0
CATEGORIES=	misc
MASTER_SITES=	http://code.coreboot.org/p/seabios/downloads/get/

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Open source implementation of a 16bit X86 BIOS

LICENSE=	LGPL3

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to x86

USES=	gmake python:build

MAKE_ARGS=	HOSTCC="${CC}" LD32BIT_FLAG="-melf_i386_fbsd" \
		PYTHON="${PYTHON_CMD}"
USE_GCC=	yes

PLIST_FILES=	${DATADIR}/bios.bin

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/out/bios.bin ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
RUN_DEPENDS:=	${RUN_DEPENDS:Ngcc*}
