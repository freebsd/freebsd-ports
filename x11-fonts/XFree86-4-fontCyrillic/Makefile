# New ports collection makefile for:	XFree86-fontCyrillic
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontCyrillic
PORTVERSION=	4.2.0
PORTREVISION=   4
CATEGORIES=	x11-fonts
MASTER_SITES=   ${MASTER_SITE_XFREE:S/$/:x/} \
		http://koi8.pp.ru/dist/:xrus
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x
PKGNAMEPREFIX=	XFree86-
DISTFILES=      X${PORTVERSION:S/.//g}src-2.tgz:x \
		xrus-2.3.1-xf4-bdf.tgz:xrus

MAINTAINER=	anholt@freebsd.org

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

XFREE86_VERSION=	4
USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
EXTRACT_ONLY=           X${PORTVERSION:S/.//g}src-2.tgz
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/fonts
WRKSRC=			${WRKDIR}/xc/fonts/bdf/cyrillic

post-extract:
	cd ${WRKSRC} && \
	    ${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/xrus-2.3.1-xf4-bdf.tgz

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

pre-build:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 ${MAKE} all)

.include <bsd.port.mk>
