# New ports collection Makefile for:    exmh2
# Version required:		2.0zeta
# Date released:		1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.12 1997/07/13 18:49:22 max Exp $
#

DISTNAME=	exmh-2.0zeta
PKGNAME=	exmh-2.0z
CATEGORIES=	mail tk41
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/exmh/
EXTRACT_SUFX=	.tar.Z

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
