# New ports collection Makefile for:    exmh2
# Version required:		2.0delta
# Date released:		1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.11 1997/07/08 02:45:57 peter Exp $
#

DISTNAME=	exmh-2.0delta
PKGNAME=	exmh-2.0d
CATEGORIES=	mail tk41
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/exmh/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	http://www.sunlabs.com/~bwelch/exmh/patches/2.0delta/
PATCHFILES=	getnews.patch ispell.patch addr.patch post.patch \
		fontsel.patch html_get_http.patch sedit.patch \
		html_formtag.patch editor.patch thread.patch \
		pgp.patch mime.patch fcache.patch
PATCH_DIST_ARGS=	-d ${WRKSRC}/lib --forward --quiet -E

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
		FILESDIR=${FILESDIR} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include <bsd.port.mk>
