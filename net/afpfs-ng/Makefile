# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	afpfs-ng
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	The afpfs-ng is an Apple Filing Protocol client library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	FUSE GCRYPT

USE_BZIP2=	yes
USE_GCC=	any
USES=		iconv gmake
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes

CFLAGS+=	-D_FILE_OFFSET_BITS=64 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--prefix="${PREFIX}"

MAN1=		afpcmd.1 afpgetstatus.1

.if ${PORT_OPTIONS:MFUSE}
LIB_DEPENDS+=	 fuse:${PORTSDIR}/sysutils/fusefs-libs
CONFIGURE_ARGS+=--enable-fuse
.else
CONFIGURE_ARGS+=--disable-fuse
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--enable-gcrypt
.else
CONFIGURE_ARGS+=--disable-gcrypt
.endif

.include <bsd.port.pre.mk>

post-patch:	.SILENT
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.am

post-configure: .SILENT
	${REINPLACE_CMD} 's|LIBS = |LIBS = ${ICONV_LIB} |' \
		${WRKSRC}/cmdline/Makefile

.include <bsd.port.post.mk>
