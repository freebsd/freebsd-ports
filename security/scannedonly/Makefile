# Created by: girald@etcom.ufrgs.br
# $FreeBSD$

PORTNAME=	scannedonly
PORTVERSION=	0.21
CATEGORIES=	security
MASTER_SITES=	http://olivier.sessink.nl/scannedonly/

MAINTAINER=	girald@etcom.ufrgs.br
COMMENT=	A Samba VFS virus scanning daemon

LICENSE=	GPLv2

LIB_DEPENDS=	clamav:${PORTSDIR}/security/clamav
RUN_DEPENDS=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav \
		smbd:${PORTSDIR}/${SAMBA_PORT}
BUILD_DEPENDS+=	smbd:${PORTSDIR}/${SAMBA_PORT}

CONFIGURE_ARGS+=--with-samba-vfs-dir=${PREFIX}/lib/samba/vfs
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/sbin/smbd)
SAMBA_VERSION!=	${LOCALBASE}/sbin/smbd --version | ${CUT} -d ' ' -f 2
.else
SAMBA_VERSION?=	3.6
.endif

SAMBA_PORT?=	net/samba${SAMBA_VERSION:C/([0-9]*)\.([0-9]*).*/\1\2/}

PLIST_FILES=	sbin/scannedonlyd_clamav \
		bin/scannedonly_prescan
MAN8=		${PORTNAME}_prescan.8 \
		${PORTNAME}d_clamav.8
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} \
	    -e 's|/var/lib/scannedonly/scan|/var/run/scannedonlyd.sock|g' \
	${WRKSRC}/man/scannedonly_prescan.8	\
	${WRKSRC}/py/scannedonlyd.py		\
	${WRKSRC}/src/vfs_scannedonly.c		\
	${WRKSRC}/src/scannedonly_prescan.c	\
	${WRKSRC}/src/scannedonlyd_clamav.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
