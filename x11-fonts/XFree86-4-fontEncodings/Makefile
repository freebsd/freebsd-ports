# New ports collection makefile for:	XFree86XfontEncodings-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontEncodings
PORTVERSION=	4.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/${PORTVERSION}/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/${PORTVERSION}/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-${PORTVERSION}/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/${PORTVERSION}/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/${PORTVERSION}/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X401src-2.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

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
