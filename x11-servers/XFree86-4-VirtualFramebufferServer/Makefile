# New ports collection makefile for:	XFree86-VirtualFramebufferServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	VirtualFramebufferServer
PORTVERSION=	4.2.1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_XFREE:S/source//g:S/$/:x421patch/} \
		${MASTER_SITE_XFREE:S/source//g:S/$/:x421fixes/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	4.2.0/:x \
			${PORTVERSION}/patches/:x421patch \
			${PORTVERSION}/fixes/:x421fixes \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X420src-1.tgz:x \
		4.2.0-4.2.1.diff.gz:x421patch \
		4.2.1-mit-shm-security.patch:x421fixes \
		Wraphelp.gz:local
EXTRACT_ONLY=	X420src-1.tgz

MAINTAINER=	anholt@freebsd.org

RUN_DEPENDS=	${FONT}:${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps

FONT=	${X11BASE}/lib/X11/fonts/misc/cursor.pcf.gz

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
MAN1=			Xserver.1 Xvfb.1
XBUILD_DIRS=		lib/font lib/lbxutil/ lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		programs/Xserver
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

pre-patch::
	-@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/4.2.0-4.2.1.diff.gz \
		| ${PATCH} -d ${PATCH_WRKSRC} --forward --quiet -E -p1 --batch
	-@${CAT} ${DISTDIR}/${DIST_SUBDIR}/4.2.1-mit-shm-security.patch \
		| ${PATCH} -d ${PATCH_WRKSRC} --forward --quiet -E -p1 --batch

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.mk>
