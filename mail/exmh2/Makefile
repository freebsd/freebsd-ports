# New ports collection Makefile for:    exmh2
# Version required:		2.0.2
# Date released:		1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.27 1998/03/20 09:28:05 markm Exp $
#

DISTNAME=	exmh-2.0.2
CATEGORIES=	mail tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/exmh/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	http://sunscript.sun.com/exmh/patches/2.0.1/
#PATCHFILES=	utils.patch folderNew.patch extrasInit.patch exec.patch \
#		app-defaults.patch pgpMisc.patch seditMime.patch mime.patch \
#		bindings.patch html_bindings.patch find.patch mh.patch \
#		pgp.patch

# User contributed and "new features".  Some not useable as-is.
PATCHFILES+=	seditpost.patch inc.patch next.patch
# XXX pgpExec.patch has got confused paths	(supplied as patch-as)
# XXX newsgroups.patch is relative to a different directory (patch-at)
# XXX MDN.patch doesn't apply			(patch-au)
# XXX post.from.patch doesn't apply		(patch-av)

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
.if defined(USE_NMH)
RUN_DEPENDS+=	repl:${PORTSDIR}/mail/nmh
SCRIPTS_ENV+=	USE_NMH=YES
.else
RUN_DEPENDS+=	repl:${PORTSDIR}/mail/mh
.endif

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
		${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include <bsd.port.mk>
