# New ports collection makefile for:	scannedonly
# Date created:				20 January 2011
# Whom:					girald@etcom.ufrgs.br
#
# $FreeBSD$
#

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

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/sbin/smbd)
SAMBA_VERSION!=	${LOCALBASE}/sbin/smbd --version | ${CUT} -d ' ' -f 2
.else
SAMBA_VERSION?=	3.6
.endif

SAMBA_PORT?=	net/samba${SAMBA_VERSION:C/([0-9]*)\.([0-9]*).*/\1\2/}

# If samba34 is installed, we need the sources from samba.
# We don't if samba3[56] is installed.
# http://olivier.sessink.nl/scannedonly/faq.html
.if ${SAMBA_PORT} == net/samba34
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/${SAMBA_PORT}:configure
CONFIGURE_ARGS+=\
	--with-samba-source=${WRKDIR}/../../../${SAMBA_PORT}/work/samba-${SAMBA_VERSION}/source3
USE_AUTOTOOLS=	autoconf
.endif

PLIST_FILES=	sbin/scannedonlyd_clamav \
		bin/scannedonly_prescan
.if ${SAMBA_PORT} == net/samba34
PLIST_FILES+=	lib/samba/vfs/scannedonly.so
PLIST_DIRS=	lib/samba/vfs \
		lib/samba
.endif
MAN8=		${PORTNAME}_prescan.8 \
		${PORTNAME}d_clamav.8
MANCOMPRESSED=	yes

# Hackery to avoid death for non-obvious reasons if detected
# SAMBA_VERSION doesn't match the PORTVERSION of samba in ports
pre-everything::
.if ${SAMBA_PORT} == net/samba34
	@if [ "$$(${MAKE} -C ${PORTSDIR}/${SAMBA_PORT} -V PORTVERSION)" \
		!= "${SAMBA_VERSION}" ] ; \
	    then ${ECHO_MSG} -n "==> Bailing.  Version of Samba on system is "; \
		${ECHO_MSG} "${SAMBA_VERSION}, which does not match" ; \
		${ECHO_MSG} "    that in ports.  Please update Samba and try again." ; \
		${FALSE} ; \
	    fi
.endif

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
