# New ports collection makefile for:	XFree86XVirtualFramebufferServer-4.0.1
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	VirtualFramebufferServer
PORTVERSION=	4.0.1
CATEGORIES=	x11-servers
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0.1/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0.1/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0.1/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0.1/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0.1/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X401src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${PORTSDIR}/x11/XFree86-4-libraries/patches
SCRIPTS_ENV+=		PREFIX=${PREFIX} \
			X11BASE=${X11BASE} \
			WRKDIR=${WRKDIR} \
			DISTDIR=${DISTDIR}
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET= 	installXvfb installXvfb.man
MANCOMPRESSED=		yes
MAN1=			Xserver.1 Xvfb.1

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.mk>
