# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	afpfs-ng
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Apple Filing Protocol client library

LICENSE=	GPLv2

INSTALL_TARGET=	install-strip
USES=		gmake iconv libtool tar:bzip2
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
AUTOMAKE_ARGS=	--add-missing --copy --force
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-return-type
CPPFLAGS+=	-D_FILE_OFFSET_BITS=64 -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	FUSE GCRYPT

FUSE_LIB_DEPENDS=	libfuse.so:${PORTSDIR}/sysutils/fusefs-libs
FUSE_CONFIGURE_ENABLE=	fuse

GCRYPT_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_ENABLE=gcrypt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFUSE}
PLIST_FILES+=	bin/afp_client bin/afpfs bin/afpfsd bin/mount_afp \
		man/man1/afp_client.1.gz man/man1/afpfsd.1.gz \
		man/man1/mount_afp.1.gz
.endif

post-configure:
	@${REINPLACE_CMD} 's|LIBS = |LIBS = ${ICONV_LIB} |' \
		${WRKSRC}/cmdline/Makefile

.include <bsd.port.mk>
