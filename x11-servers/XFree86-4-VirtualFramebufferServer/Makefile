# New ports collection makefile for:	XFree86XVirtualFramebufferServer-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	VirtualFramebufferServer
PORTVERSION=	4.0
CATEGORIES=	x11-servers
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X400src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4
LIB_DEPENDS=	X11.6:${PORTSDIR}/x11/XFree86-4-libraries

PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc
PATCHDIR=	${PORTSDIR}/x11/XFree86-4-libraries/patches
SCRIPTS_ENV+=	PREFIX=${PREFIX} \
		X11BASE=${X11BASE} \
		WRKDIR=${WRKDIR} \
		DISTDIR=${DISTDIR}
ALL_TARGET=	FreeBSDPortsBuild
.if defined(NO_INSTALL_MANPAGES)
INSTALL_TARGET= installXvfb
.else
INSTALL_TARGET= installXvfb installXvfb.man
MANCOMPRESSED=	yes
MAN1=		Xvfb.1
.endif

.include <bsd.port.mk>
