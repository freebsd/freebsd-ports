# New ports collection makefile for:	XFree86XfontEncodings-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontEncodings
PORTVERSION=	4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X400src-2.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4 \
		mkfontdir:${PORTSDIR}/x11/XFree86-4-libraries

PREFIX?=	${X11BASE}
PROJECTROOT=	-DProjectRoot=${PREFIX}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc/fonts/encodings

do-configure:
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.mk>
