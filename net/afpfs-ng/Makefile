PORTNAME=	afpfs-ng
PORTVERSION=	0.8.1
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Apple Filing Protocol client library
WWW=		https://sourceforge.net/projects/afpfs-ng/

LICENSE=	GPLv2

USES=		autoreconf gmake iconv libtool localbase readline shebangfix tar:bzip2
USE_LDCONFIG=	yes

SHEBANG_FILES=	fuse/afpfs

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

CFLAGS+=	-Wno-return-type
CPPFLAGS+=	-D_FILE_OFFSET_BITS=64

OPTIONS_DEFINE=	FUSE GCRYPT
OPTIONS_SUB=	yes

FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs
FUSE_CONFIGURE_ENABLE=	fuse
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CONFIGURE_ENABLE=gcrypt

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-configure:
	@${REINPLACE_CMD} 's|LIBS = |LIBS = ${ICONV_LIB} |' \
		${WRKSRC}/cmdline/Makefile

.include <bsd.port.mk>
