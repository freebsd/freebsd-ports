# New ports collection makefile for:	XFree86XVirtualFramebufferServer-4.0.1
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	VirtualFramebufferServer
PORTVERSION=	4.0.3
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.0.2
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X402src-1.tgz

PATCH_SITES=	${MASTER_SITE_XFREE:S,%SUBDIR%/source,4.0.3/patches,g}
PATCHFILES=	4.0.2-4.0.3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET= 	installXvfb installXserver.man
MAKE_ENV=		MAN_INSTALL_TARGET=installXvfb.man
MAN1=			Xserver.1 Xvfb.1

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.mk>
