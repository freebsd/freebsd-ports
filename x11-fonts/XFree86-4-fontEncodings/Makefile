# New ports collection makefile for:	XFree86-fontEncodings
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontEncodings
PORTVERSION=	4.2.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-2.tgz

MAINTAINER=	anholt@freebsd.org

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients

XFREE86_VERSION=	4
USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/fonts
WRKSRC=			${WRKDIR}/xc/fonts/encodings

do-configure:
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.mk>
