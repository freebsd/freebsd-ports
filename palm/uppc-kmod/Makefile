# New ports collection makefile for:	uppc-kmod
# Date created:				31 August 2003
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	uppc
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	palm kld
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}-${PKGNAMESUFFIX}/sources/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USB device driver for Windows CE handhelds

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN4=		uppc.4
WRKSRC=		${WRKDIR}/${PORTNAME}

.if !exists(${SRC_BASE}/sys/dev/usb/usb.h)
IGNORE=		Requires kernel source (in ${SRC_BASE}) to build
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

post-build:
	@${REINPLACE_CMD} -e 's|%%INITIAL_INSTALLDIR%%|${PREFIX}/lib|g' ${BUILD_WRKSRC}/uppcsetup
	@${REINPLACE_CMD} -e 's|%%INITIAL_MODDIR%%|${KMODDIR}|g' ${WRKSRC}/uppcsetup

do-install:
	${INSTALL_KLD} ${WRKSRC}/uppc.ko ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/uppcsetup ${PREFIX}/sbin
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN4} ${MANPREFIX}/man/man4

post-install:
	@${ECHO_CMD} "       ****************************************************************"
	@${ECHO_CMD} "       * You can run 'uppcsetup' to help configure the device driver  *"
	@${ECHO_CMD} "       * and set up a connection.                                     *"
	@${ECHO_CMD} "       ****************************************************************"

.include <bsd.port.post.mk>
