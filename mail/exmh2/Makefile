# New ports collection Makefile for:    exmh
# Version required:		1.6.9
# Date released:		10 Oct 96
# Whom:				Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.2 1996/10/15 11:27:26 peter Exp $
#

DISTNAME=	exmh-1.6.9
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

# It will use these commands to view faces or play audio, we dont have ports.
# faces
# play

post-extract:
	@rm -rf ${WRKSRC}/lib/*.orig

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SCRIPTDIR}/install
.if !defined(NOMANCOMPRESS)
	gzip -9f ${PREFIX}/man/man1/exmh-custom.1
	gzip -9f ${PREFIX}/man/man1/exmh-ref.1
	gzip -9f ${PREFIX}/man/man1/exmh-use.1
	gzip -9f ${PREFIX}/man/man1/exmh.1
.endif

.include <bsd.port.mk>
