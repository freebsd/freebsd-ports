# New ports collection makefile for:   flashplugin
# Date created:        3 October 1999
# Whom:                Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	0.4.3
CATEGORIES=	www graphics
MASTER_SITES=	http://www.geocities.com/TimesSquare/Labyrinth/5084/flash/Linux/ \
		http://perso.club-internet.fr/odebon/flash/Linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of Macromedia Flash plugin for Netscape

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
MASTER_SITES=	http://www.geocities.com/TimesSquare/Labyrinth/5084/flash/Linux/ \
		http://perso.club-internet.fr/odebon/flash/Linux/
DISTNAME=	flash-${PORTVERSION}
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://leed.t.u-tokyo.ac.jp/~yamagata/flash/
PATCHFILES=	flash-0.4.3-fbsd-19990512.patch

USE_XLIB=	yes
MAKE_ENV=	OBJFORMAT=aout LIBRARY_PATH=${PREFIX}/lib/aout
PORTOBJFORMAT=	aout
ALL_TARGET=	libswf.so

pre-build:
.if !exists(/usr/lib/aout/c++rt0.o)
	@${CAT} ${FILESDIR}/message.nolib
	@${FALSE}
.endif
.else
MASTER_SITES=	http://leed.t.u-tokyo.ac.jp/~yamagata/flash/
DISTNAME=	libswf-19990503.so
EXTRACT_SUFX=	.gz

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${GUNZIP_CMD} -c ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/libswf.so

do-patch:
	@${DO_NADA}
.endif

TARGETDIR=	${PREFIX}/lib/netscape/plugins

do-install:
.if !defined(PACKAGE_BUILDING)
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL
.endif
	${MKDIR} ${TARGETDIR}
	${SETENV} OBJFORMAT=aout ${INSTALL_SCRIPT} ${WRKSRC}/libswf.so ${TARGETDIR}

.include <bsd.port.post.mk>
