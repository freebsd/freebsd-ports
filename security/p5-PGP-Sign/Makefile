# New ports collection makefile for: p5-PGP-Sign
# Version required:	0.13
# Date created:		January 2, 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.4 1998/09/15 21:31:53 asami Exp $
#

DISTNAME=	PGP-Sign-0.13
PKGNAME=	p5-PGP-Sign-0.13
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGP

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp

USE_PERL5=	yes

MAN3=		PGP::Sign.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

# This module only works with version 2, so you need to set this
# variable on the command line if you have something else installed as
# pgp.
.ifndef PGP
PGP!=	which pgp || echo ${PREFIX}/bin/pgp
.endif

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PGP=${PGP}

.include <bsd.port.mk>
