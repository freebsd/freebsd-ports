# New ports collection makefile for: pgp5
# Version required:     International PGP 5.0
# International PGP homepage is http://www.ifi.uio.no/pgp/
#
# Date created:         10 Feb 1998
# Whom:                 markm
#
# $FreeBSD$
#

DISTNAME=	pgp50i
PKGNAME=	pgp-5.0i
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.ifi.uio.no/pub/pgp/5.0/unix/ \
		ftp://ftp.doc.ic.ac.uk/pub/Mirrors/ftp.ifi.uio.no/pub/pgp/5.0/unix/
EXTRACT_SUFX=   -unix-src.tar.gz

MAINTAINER=	markm@FreeBSD.org

Y2K=		http://www.pgpi.com/faq/pgpi.shtml#Year2000

WRKSRC=		${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX}
RESTRICTED=     "Crypto"
MAN1=		pgp5.1 pgpe.1 pgpk.1 pgps.1 pgpv.1
MAN5=		pgp.cfg.5
MAN7=		pgp-integration.7 pgp-intro.7

.include <bsd.port.mk>
