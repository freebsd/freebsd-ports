# New ports collection makefile for:	XFree86-NestServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	NestServer
PORTVERSION=	4.4.0
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-4.4.0-src-1.tgz:x \
		XFree86-4.4.0-src-2.tgz:x \
		XFree86-4.4.0-src-3.tgz:x \
  		Wraphelp2.gz:local
EXTRACT_ONLY=	XFree86-4.4.0-src-1.tgz \
		XFree86-4.4.0-src-2.tgz \
		XFree86-4.4.0-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 nested X server

CONFLICTS=	xorg-nestserver-*

MAN1=			Xnest.1
EXTRA_PATCHES+=		${FILESDIR}/patch-programs::Xserver::Xext::Imakefile
XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver/hw/xnest

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp2.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
