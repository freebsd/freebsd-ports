# New ports collection Makefile for:    exmh2
# Version required:		2.0delta
# Date released:		1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.8 1997/04/20 13:19:17 wosch Exp $
#

DISTNAME=	exmh-2.0delta
PKGNAME=	exmh-2.0d
CATEGORIES=	mail tk41
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/exmh/
EXTRACT_SUFX=	.tar.Z

# Note: due to apparent weaknesses in bsd.port.mk, we have to override the
# PATCH_DIST_ARGS variable *after* .include <bsd.port.mk> in order to supply
# second "-d directory" arg to patch (to override the one that's not optional
# and unusable for us here).  These patches are relative to the ${WRKSRC}/lib
# subdir, bsd.port.mk can't handle that.
PATCH_SITES=	http://www.sunlabs.com/~bwelch/exmh/patches/2.0delta/
PATCHFILES=	getnews.patch ispell.patch addr.patch post.patch \
		fontsel.patch html_get_http.patch sedit.patch \
		html_formtag.patch editor.patch thread.patch \
		pgp.patch mime.patch fcache.patch

MAINTAINER=	peter@FreeBSD.org

DIST_SUBDIR=	${PKGNAME}

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
WISH=		wish4.1

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
		FILESDIR=${FILESDIR} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SCRIPTDIR}/install

.include <bsd.port.mk>

PATCH_DIST_ARGS+=	-d ${WRKSRC}/lib
