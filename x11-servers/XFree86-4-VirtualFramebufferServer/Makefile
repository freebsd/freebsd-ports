# New ports collection makefile for:	XFree86-VirtualFramebufferServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	VirtualFramebufferServer
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE} \
		ftp://psych.psy.uq.oz.au/pub/X11R5/:wrap \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/:wrap \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/:wrap
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-1.tgz Wraphelp.c:wrap
EXTRACT_ONLY=	X${PORTVERSION:S/.//g}src-1.tgz
IGNOREFILES=	Wraphelp.c

MAINTAINER=	anholt@freebsd.org

RUN_DEPENDS=	${FONT}:${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps

FONT=	${X11BASE}/lib/X11/fonts/misc/cursor.pcf.gz

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET=		installXvfb installXserver.man
MAKE_ENV=		MAN_INSTALL_TARGET=installXvfb.man
MAN1=			Xserver.1 Xvfb.1

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/Wraphelp.c ${WRKSRC}/lib/Xdmcp/

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@cd ${WRKSRC}; ${MAKE} FreeBSDPortsConfigure

.include <bsd.port.mk>
