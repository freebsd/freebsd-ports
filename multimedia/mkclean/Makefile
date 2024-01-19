PORTNAME=	mkclean
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clean and optimize Matroska and WebM files
WWW=		https://www.matroska.org/downloads/mkclean.html

LICENSE=	BSD3CLAUSE

# These may work better now with cmake.
BROKEN_aarch64=	does not install: arm-none-linux-gnueabi-gcc: Command not found
BROKEN_armv6=	does not install: arm-none-linux-gnueabi-gcc: Command not found
BROKEN_armv7=	does not install: arm-none-linux-gnueabi-gcc: Command not found
BROKEN_mips64=	does not install: mipsel-linux-gcc: Command not found
BROKEN_riscv64=	does not compile: cc: invalid arch name 'i486', string must begin with rv32{i,e,g} or rv64{i,g}

USES=		cmake compiler:c++11-lang cpe iconv localbase:ldflags

CPE_VENDOR=	matroska

USE_GITHUB=	yes
GH_ACCOUNT=	Matroska-Org
GH_PROJECT=	foundation-source

NO_INSTALL=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/vfs.h/mount.h/' ${WRKSRC}/corec/corec/helpers/file/file_libc.c

LDFLAGS+=	${ICONV_LIB}

PLIST_FILES=	bin/mkclean \
		bin/mkWDclean

post-stage:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME}/mkclean ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME}/mkWDclean ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
