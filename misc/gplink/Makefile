# New ports collection makefile for:	gplink
# Date created:				Sun Dec  5 23:17:44 CET 2004
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	gplink
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://gp2x.org/gp32/gplink/ \
		http://www.gnu-darwin.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GP32 USB linker tool

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS} ${USB_CFLAGS}" \
		LDFLAGS="${USB_LDFLAGS}"
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/gplink

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
USB_CFLAGS=	`libusb-config --cflags`
USB_LDFLAGS=	`libusb-config --libs`
.else
USB_CFLAGS=	# none
USB_LDFLAGS=	-lusb
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplink ${PREFIX}/bin

.include <bsd.port.post.mk>
