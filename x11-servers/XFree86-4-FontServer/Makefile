# New ports collection makefile for:	XFree86-FontServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	FontServer
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	x11-servers x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-1.tgz
EXTRACT_ONLY=	X${PORTVERSION:S/.//g}src-1.tgz

MAINTAINER=	anholt@freebsd.org

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
SCRIPTS_ENV=		CC="${CC}" \
			CXX="${CXX}" \
			CFLAGS="${CFLAGS}"
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
MAN1=			Xserver.1 xfs.1
XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans programs/Xserver 
XINSTALL_MAN_DIRS=	programs/Xserver programs/xfs


.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.mk>
