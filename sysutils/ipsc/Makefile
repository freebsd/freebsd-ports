# New ports collection makefile for:	ipsc
# Date created:		31 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	ipsc
PORTVERSION=	0.4.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://ipsc.sourceforge.net/dist/ipsc/
DISTNAME=	${PKGNAME}-src

MAINTAINER=	jeremy@external.org

BUILD_DEPENDS=	${WRKDIRPREFIX}${PORTSDIR}/sysutils/prips/work/prips/prips.o:${PORTSDIR}/sysutils/prips:build
.if defined(WITH_GNOME)
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gnome.3:${PORTSDIR}/x11/gnomelibs
.endif

.if defined(WITH_GNOME)
USE_XLIB=	YES
.endif
WRKSRC=		${WRKDIR}/ipsc/src

post-extract:
	@${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../prips/work/prips \
		${WRKDIR}/prips

pre-build:
.if defined(WITH_GNOME)
PLIST=		${PKGDIR}/PLIST.gnome
ALL_TARGET=	all
.else
ALL_TARGET=	ipsc
.endif

post-build:
.if defined(WITH_GNOME)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Don't forget to define WITH_GNOME when installing"
	@${ECHO_MSG} ""
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ipsc ${PREFIX}/bin
.if defined(WITH_GNOME)
	@${INSTALL_PROGRAM} ${WRKSRC}/gipsc ${PREFIX}/bin
.endif

.include <bsd.port.mk>
