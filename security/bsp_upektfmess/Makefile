# Ports collection makefile for:	bsp_upektfmess
# Date created:			February 2006
# Whom:				Fredrik Lindberg <fli@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	bsp_upektfmess
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.upek.com/support/download/ \
		http://www.shapeshifter.se/pub/bsp_upektfmess/
DISTNAME=	TFMESS_BSP_FreeBSD_1.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UPEK TouchChip TFM/ESS Fingerprint BSP

LIB_DEPENDS=	bioapi100.0:${PORTSDIR}/security/bioapi \
		usb-0.1.8:${PORTSDIR}/devel/libusb
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xext.pc:${PORTSDIR}/x11/libXext

PLIST_FILES=	lib/libtfmessbsp.so

USE_ZIP=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
# Maintainer note
# Both the gui and the non-gui object are linked to libX11
USE_XORG=	x11 xext

RESTRICTED=	license prohibits redistribution
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

OPTIONS=	GUI "Install GUI" off

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700000
IGNORE=		needs at least FreeBSD 7.0-RELEASE
.endif

.if defined(WITH_GUI)
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
.if defined(WITH_GUI)
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

.include <bsd.port.post.mk>
