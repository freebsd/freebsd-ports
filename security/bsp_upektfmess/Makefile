# Created by: Fredrik Lindberg <fli@shapeshifter.se>
# $FreeBSD$

PORTNAME=	bsp_upektfmess
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.upek.com/support/download/ \
		http://www.shapeshifter.se/pub/bsp_upektfmess/
DISTNAME=	TFMESS_BSP_FreeBSD_1.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UPEK TouchChip TFM/ESS Fingerprint BSP

LIB_DEPENDS=	bioapi100.0:${PORTSDIR}/security/bioapi
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xext.pc:${PORTSDIR}/x11/libXext

PLIST_FILES=	lib/libtfmessbsp.so

USE_LDCONFIG=	yes
USES=		gettext iconv zip
# Maintainer note
# Both the gui and the non-gui object are linked to libX11
USE_XORG=	x11 xext

RESTRICTED=	license prohibits redistribution
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

OPTIONS_DEFINE=	GUI

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
TFMESSPATH=${WRKDIR}/${DISTNAME}
.else
TFMESSPATH=${WRKDIR}/${DISTNAME}/console_only
.endif

do-install:
.if !defined(BATCH)
	${SH} ${PKGREQ} ${PORTNAME} INSTALL
.endif
	${INSTALL} -o root -m 0755 ${TFMESSPATH}/libtfmessbsp.so ${PREFIX}/lib
	${PREFIX}/bin/mod_install -fi ${PREFIX}/lib/libtfmessbsp.so

post-install:
.if !defined(BATCH)
	@${ECHO_CMD} ""
.if ${PORT_OPTIONS:MGUI}
	@${ECHO_CMD} "You have chosen to install the GUI version, this does"
	@${ECHO_CMD} "not always work correctly with PAM."
	@${ECHO_CMD} "Please install the non-gui version if you intend to"
	@${ECHO_CMD} "use this together with PAM."
	@${ECHO_CMD} ""
.endif
	@${ECHO_CMD} "Configuration instructions are available at"
	@${ECHO_CMD} "http://www.shapeshifter.se/articles/upek_touchchip_freebsd/"
	@${ECHO_CMD} ""
.endif

.include <bsd.port.mk>
