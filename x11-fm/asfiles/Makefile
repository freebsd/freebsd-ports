# New ports collection makefile for:   ASFiles
# Date created:                17 August 1997
# Whom:                        lukin@okbmei.msk.su
#
# $FreeBSD$
#

PORTNAME=	asfiles
PORTVERSION=	1.0
CATEGORIES=	x11-fm afterstep windowmaker
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	apps/ASFiles
DISTNAME=	ASFiles-${PORTVERSION}

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	Dnd.1:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
MAN1=	files.1
MAN3=	regexp.3

post-install:
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/last-patch-aa
	${INSTALL_DATA} ${WRKSRC}/src/Files.ad ${PREFIX}/lib/X11/app-defaults/
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${MV} ${WRKSRC}/src/Files.ad.orig ${WRKSRC}/src/Files.ad

.include <bsd.port.mk>
