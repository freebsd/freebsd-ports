# New ports collection Makefile for:    exmh2
# Version required:		2.0.1
# Date released:		1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.23 1997/12/26 07:11:40 peter Exp $
#

DISTNAME=	exmh-2.0.1
CATEGORIES=	mail tk80
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/exmh/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	http://www.sunlabs.com/~bwelch/exmh/patches/2.0.1/
PATCHFILES=	folderNew.patch seditpost.patch extrasInit.patch
# XXX newsgroups.patch is relative to a different directory

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS= -d ${WRKSRC}/lib -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS= -d ${WRKSRC}/lib --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

MAINTAINER=	peter@FreeBSD.org

DIST_SUBDIR=	${PKGNAME}

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
WISH=		wish8.0
TCLSH=		tclsh8.0

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
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include <bsd.port.mk>
