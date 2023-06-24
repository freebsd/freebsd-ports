PORTNAME=	shx
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://synhxd.sourceforge.net/releases/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}.diff.gz

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Text based Hotline Communications client for Unix
WWW=		http://synhxd.sourceforge.net/

LICENSE=	GPLv1

USES=		readline ssl tar:tgz

GNU_CONFIGURE=	yes

MAKEFILE=	makefile

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

CONFLICTS_INSTALL=	helix # bin/hx

PLIST_FILES=	bin/hx				\
		share/examples/shx/hxrc		\
		share/examples/shx/hxvars

OPTIONS_DEFINE=	WARNINGS HTXF_PTHREAD HFS HOPE CIPHER COMPRESS HAL XMMS NOIPV4
OPTIONS_DEFAULT=HTXF_PTHREAD HFS HOPE CIPHER COMPRESS XMMS

CIPHER_DESC=		Enable Cipher (HOPE required)
COMPRESS_DESC=		Enable Compress (HOPE required)
HAL_DESC=		Compile MegaHAL (enables hal command)
HFS_DESC=		Enable HFS file system emulation
HOPE_DESC=		Enable HOPE (required by Cipher/Compress)
HTXF_PTHREAD_DESC=	Use pthread instead of fork or clone for htxf
NOIPV4_DESC=		IPv6 support (disables IPv4 support)
WARNINGS_DESC=		Show compiler warnings
XMMS_DESC=		Enable trackname command

CIPHER_IMPLIES=			HOPE
CIPHER_CONFIGURE_ENABLE=	cipher
COMPRESS_IMPLIES=		HOPE
COMPRESS_CONFIGURE_ENABLE=	compress
HAL_CONFIGURE_ENABLE=		hal
HFS_CONFIGURE_ENABLE=		hfs
HOPE_CONFIGURE_ENABLE=		hope
HTXF_PTHREAD_CONFIGURE_ENABLE=	htxf-pthread
NOIPV4_CONFIGURE_ENABLE=	ipv6
WARNINGS_CONFIGURE_ENABLE=	warnings
XMMS_CONFIGURE_ENABLE=		xmms

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${CP} -fv ${WRKSRC}/run/hx ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/${PORTNAME}
	${CP} -fv ${WRKSRC}/run/hxrc ${STAGEDIR}${PREFIX}/share/examples/${PORTNAME}/
	${CP} -fv ${WRKSRC}/run/hxvars ${STAGEDIR}${PREFIX}/share/examples/${PORTNAME}/

.include <bsd.port.post.mk>
