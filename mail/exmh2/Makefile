# New ports collection Makefile for:    exmh2
# Version required:		2.0zeta
# Date released:		1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.14 1997/08/12 05:58:47 peter Exp $
#

DISTNAME=	exmh-2.0zeta
PKGNAME=	exmh-2.0z
CATEGORIES=	mail tk41
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/exmh/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	http://www.sunlabs.com/~bwelch/exmh/patches/2.0zeta/
PATCHFILES=	ispell.patch koir.patch mime.patch seditMime.patch scan.patch

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS= -d ${WRKSRC}/lib -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS= -d ${WRKSRC}/lib --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

MAINTAINER=	peter@FreeBSD.org

DIST_SUBDIR=	${PKGNAME}

# Uses wish8.0 if present (major speed improvement), else it depends on
# the tk4.1 port.  The glue for this is at the end of the file due to
# bmake quirks.

# exmh is pretty useless without this, but it's not needed to build it.
RUN_DEPENDS+=	repl:${PORTSDIR}/mail/mh

# full mime support needs mmencode/mmdecode from metamail
RUN_DEPENDS+=	mmencode:${PORTSDIR}/mail/metamail

# Additionally, exmh will use the following ports if present:
# lang/expect
# misc/glimpse
# security/pgp
# mail/faces
# audio/rplay

MAN1=		exmh.1

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include <bsd.port.mk>

# Must come after bsd.port.mk since .if is expanded on the first pass
# before $PREFIX is defined.

.if exists($(PREFIX)/bin/wish8.0)
WISH=		wish8.0
.else
RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
WISH=		wish4.1
.endif

