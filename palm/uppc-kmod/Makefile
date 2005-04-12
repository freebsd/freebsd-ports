# New ports collection makefile for:	uppc-kmod
# Date created:				31 August 2003
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	uppc
PORTVERSION=	0.7
CATEGORIES=	palm
MASTER_SITES=	http://people.tecnik93.com/~sam/ports/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	USB device driver for Windows CE handhelds

MAN4=		uppc.4
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes

.if !exists(/usr/src/sys/dev/usb/usb.h)
IGNORE=		Requires kernel source (/usr/src/sys) to build
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not build on FreeBSD 4.x"
.endif

post-build:
	@${REINPLACE_CMD} -e 's|%%INITIAL_INSTALLDIR%%|${PREFIX}/lib|g' ${BUILD_WRKSRC}/uppcsetup
	@${REINPLACE_CMD} -e 's|%%INITIAL_MODDIR%%|${KMODDIR}|g' ${WRKSRC}/uppcsetup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uppc.ko ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/uppcsetup ${PREFIX}/sbin
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN4} ${MANPREFIX}/man/man4

post-install:
	@${ECHO_CMD} "       ****************************************************************"
	@${ECHO_CMD} "       * You can run 'uppcsetup' to help configure the device driver  *"
	@${ECHO_CMD} "       * and set up a connection.                                     *"
	@${ECHO_CMD} "       ****************************************************************"

.include <bsd.port.post.mk>
