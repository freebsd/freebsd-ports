# New ports collection makefile for:   flashplugin
# Version required:    0.4.3
# Date created:        3 October 1999
# Whom:                Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	flash-0.4.3
PKGNAME=	flashplugin-0.4.3
CATEGORIES=	www graphics
MASTER_SITES=	http://www.geocities.com/TimesSquare/Labyrinth/5084/flash/Linux/ \
		http://perso.club-internet.fr/odebon/flash/Linux/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://leed.t.u-tokyo.ac.jp/~yamagata/flash/
PATCHFILES=	flash-0.4.3-fbsd-19990512.patch

MAINTAINER=	knu@idaemons.org

USE_XLIB=	yes
MAKE_ENV=	OBJFORMAT=aout LIBRARY_PATH=${PREFIX}/lib/aout
PORTOBJFORMAT=	aout
ALL_TARGET=	libswf.so

pre-build:
.if !exists(/usr/lib/aout/c++rt0.o)
	@${CAT} ${FILESDIR}/message.nolib
	@${FALSE}
.endif

do-install:
.if !defined(PACKAGE_BUILDING)
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL
.endif
	${MKDIR} ${PREFIX}/lib/netscape/plugins
	cd ${WRKSRC} && ${SETENV} OBJFORMAT=aout ${INSTALL_PROGRAM} libswf.so ${PREFIX}/lib/netscape/plugins

.include <bsd.port.mk>
