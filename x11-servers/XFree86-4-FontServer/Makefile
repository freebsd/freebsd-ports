# New ports collection makefile for:	XFree86XFontServer-4.0.1
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	FontServer
PORTVERSION=	4.0.1
CATEGORIES=	x11-servers x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X401src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${PORTSDIR}/x11/XFree86-4-libraries/files
SCRIPTS_ENV+=		PREFIX=${PREFIX} \
			X11BASE=${X11BASE} \
			WRKDIR=${WRKDIR} \
			DISTDIR=${DISTDIR}
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET= 	FreeBSDPortsInstall FreeBSDPortsInstall.man
MANCOMPRESSED=		yes
MAN1=			Xserver.1 xfs.1

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.mk>
