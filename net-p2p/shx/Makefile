# Created by: Devin Teske <dteske@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shx
PORTVERSION=	0.2.4
CATEGORIES=	net-p2p
MASTER_SITES=	http://synhxd.sourceforge.net/releases/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}.diff.gz

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	A text based Hotline Communications client for Unix

LICENSE=	GPLv1

OPTIONS_DEFINE=	WARNINGS HTXF_PTHREAD HFS HOPE CIPHER COMPRESS HAL XMMS NOIPV4
OPTIONS_DEFAULT=	HTXF_PTHREAD HFS HOPE CIPHER COMPRESS XMMS

WARNINGS_DESC=		Show compiler warnings
HTXF_PTHREAD_DESC=	Use pthread instead of fork or clone for htxf
HFS_DESC=		Enable HFS file system emulation
HOPE_DESC=		Enable HOPE (required by Cipher/Compress)
CIPHER_DESC=		Enable Cipher (HOPE required)
COMPRESS_DESC=		Enable Compress (HOPE required)
HAL_DESC=		Compile MegaHAL (enables hal command)
XMMS_DESC=		Enable trackname command
NOIPV4_DESC=		IPv6 support (disables IPv4 support)

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWARNINGS}
CONFIGURE_ARGS+=	--enable-warnings
.endif

.if ${PORT_OPTIONS:MHTXF_PTHREAD}
CONFIGURE_ARGS+=	--enable-htxf-pthread
.endif

.if ! ${PORT_OPTIONS:MHFS}
CONFIGURE_ARGS+=	--disable-hfs
.endif

.if ${PORT_OPTIONS:MHOPE}
CONFIGURE_ARGS+=	--enable-hope
.if ${PORT_OPTIONS:MCIPHER}
CONFIGURE_ARGS+=	--enable-cipher
.endif
.if ${PORT_OPTIONS:MCOMPRESS}
CONFIGURE_ARGS+=	--enable-compress
.endif
.endif

.if ${PORT_OPTIONS:MHAL}
CONFIGURE_ARGS+=	--enable-hal
.endif

.if ${PORT_OPTIONS:MXMMS}
CONFIGURE_ARGS+=	--enable-xmms
.endif

.if ${PORT_OPTIONS:MNOIPV4}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

PLIST_FILES=	\
		bin/hx				\
		share/examples/shx/hxrc		\
		share/examples/shx/hxvars

PLIST_DIRS=	share/examples/shx

do-install:
	@${CP} -fv ${WRKSRC}/run/hx ${PREFIX}/bin/
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${CP} -fv ${WRKSRC}/run/hxrc ${PREFIX}/share/examples/${PORTNAME}/
	@${CP} -fv ${WRKSRC}/run/hxvars ${PREFIX}/share/examples/${PORTNAME}/

.include <bsd.port.mk>
