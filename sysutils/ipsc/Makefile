# New ports collection makefile for:	ipsc
# Version required:	0.3.2
# Date created:		31 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

DISTNAME=	ipsc-0.3.2-src
PKGNAME=	ipsc-0.3.2
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.interloper.net/~dan/software/dist/ipsc/

MAINTAINER=	jeremy@external.org

BUILD_DEPENDS=	${WRKDIRPREFIX}${PORTSDIR}/sysutils/prips/work/prips.o:${PORTSDIR}/sysutils/prips:build
.if defined(USE_GTK)
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.endif

WRKSRC=		${WRKDIR}/ipsc

.if defined(USE_GTK)
PLIST=		${PKGDIR}/PLIST.gtk
ALL_TARGET=     all
.else
ALL_TARGET=	ipsc
.endif

pre-build:
	@${LN} -s ${WRKDIRPREFIX}${PORTSDIR}/sysutils/prips/work/prips \
		${WRKDIR}/prips

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ipsc ${PREFIX}/bin
.if defined(USE_GTK)
	@${INSTALL_PROGRAM} ${WRKSRC}/gipsc ${PREFIX}/bin
.endif

.include <bsd.port.mk>
