# Created by: Devin Teske <dteske@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shx
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://synhxd.sourceforge.net/releases/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text based Hotline Communications client for Unix

LICENSE=	GPLv1

OPTIONS_DEFINE=	WARNINGS HTXF_PTHREAD HFS HOPE CIPHER COMPRESS HAL XMMS NOIPV4
OPTIONS_DEFAULT=HTXF_PTHREAD HFS HOPE CIPHER COMPRESS XMMS

WARNINGS_DESC=		Show compiler warnings
HTXF_PTHREAD_DESC=	Use pthread instead of fork or clone for htxf
HFS_DESC=		Enable HFS file system emulation
HOPE_DESC=		Enable HOPE (required by Cipher/Compress)
CIPHER_DESC=		Enable Cipher (HOPE required)
COMPRESS_DESC=		Enable Compress (HOPE required)
HAL_DESC=		Compile MegaHAL (enables hal command)
XMMS_DESC=		Enable trackname command
NOIPV4_DESC=		IPv6 support (disables IPv4 support)

USES=		readline ssl tar:tgz
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

CIPHER_IMPLIES=			HOPE
COMPRESS_IMPLIES=		HOPE

CIPHER_CONFIGURE_ENABLE=	cipher
COMPRESS_CONFIGURE_ENABLE=	compress
HAL_CONFIGURE_ENABLE=		hal
HFS_CONFIGURE_ENABLE=		hfs
HOPE_CONFIGURE_ENABLE=		hope
HTXF_PTHREAD_CONFIGURE_ENABLE=	htxf-pthread
NOIPV4_CONFIGURE_ENABLE=	ipv6
XMMS_CONFIGURE_ENABLE=		xmms
WARNINGS_CONFIGURE_ENABLE=	warnings

PLIST_FILES=	bin/hx				\
		share/examples/shx/hxrc		\
		share/examples/shx/hxvars

do-install:
	${CP} -fv ${WRKSRC}/run/hx ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/${PORTNAME}
	${CP} -fv ${WRKSRC}/run/hxrc ${STAGEDIR}${PREFIX}/share/examples/${PORTNAME}/
	${CP} -fv ${WRKSRC}/run/hxvars ${STAGEDIR}${PREFIX}/share/examples/${PORTNAME}/

.include <bsd.port.mk>
