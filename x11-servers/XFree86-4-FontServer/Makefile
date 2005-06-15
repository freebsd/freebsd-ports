# New ports collection makefile for:	XFree86-FontServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	FontServer
PORTVERSION=	4.5.0
CATEGORIES=	x11-servers x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-${PORTVERSION}-src-1.tgz \
		XFree86-${PORTVERSION}-src-2.tgz \
		XFree86-${PORTVERSION}-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 font server

CONFLICTS=	xorg-fontserver-*

MAN1=			xfs.1
XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans programs/Xserver
XINSTALL_MAN_DIRS=	programs/xfs
EXTRA_PATCHES+=		${FILESDIR}/patch-programs::xfs::Imakefile
USE_RC_SUBR=		yes

post-build:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		${FILESDIR}/xfs.sh >${WRKDIR}/xfs.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/xfs.sh ${PREFIX}/etc/rc.d
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
