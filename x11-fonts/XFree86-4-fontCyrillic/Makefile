# New ports collection makefile for:	XFree86-fontCyrillic
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontCyrillic
PORTVERSION=	4.2.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-2.tgz

# koi8-u commented out until will be implemented as addition, not replacement
#PATCHFILES=	cronyx-4.2.0.koi8-u.diff.gz
#PATCH_SITES=	http://people.FreeBSD.org/~sobomax/

MAINTAINER=	anholt@freebsd.org

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

XFREE86_VERSION=	4
USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/fonts
WRKSRC=			${WRKDIR}/xc/fonts/bdf/cyrillic

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

#post-build:
#	@for line in `${TAIL} -n +2 ${WRKSRC}/fonts.dir | ${AWK} '{print $$2}'`; do \
#		${ECHO_CMD} `${ECHO_CMD} $$line | ${SED} 's|koi8-r|koi8-u|'` $$line >> \
#			${WRKSRC}/fonts.alias; \
#	done

.include <bsd.port.mk>
