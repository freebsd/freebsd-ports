# New ports collection makefile for: pgp5
# Date created:         10 Feb 1998
# Whom:                 markm
#
# $FreeBSD$
#

PORTNAME=	pgp
PORTVERSION=	5.0i
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/pgp/5.0/unix/ \
		ftp://ftp.doc.ic.ac.uk/pub/Mirrors/ftp.ifi.uio.no/pub/pgp/5.0/unix/
DISTNAME=	pgp50i
EXTRACT_SUFX=	-unix-src.tar.gz

MAINTAINER=	markm@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
USE_PERL5=	yes
RESTRICTED=	"Crypto"

MAN1=		pgp5.1 pgpe.1 pgpk.1 pgps.1 pgpv.1
MAN5=		pgp.cfg.5
MAN7=		pgp-integration.7 pgp-intro.7

LATEST_LINK=	pgp5

.include <bsd.port.mk>
