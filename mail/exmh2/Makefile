# New ports collection Makefile for:    exmh2
# Version required:		2.0gamma
# Date released:		1 Jan 97
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.6 1997/01/02 12:53:02 asami Exp $
#

DISTNAME=	exmh-2.0gamma
PKGNAME=	exmh-2.0g
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/exmh/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	peter@FreeBSD.org

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
