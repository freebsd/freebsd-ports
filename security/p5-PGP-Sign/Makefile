# New ports collection makefile for: p5-PGP-Sign
# Version required:	0.09
# Date created:		January 2, 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.3 1998/08/24 00:43:52 steve Exp $
#

DISTNAME=	PGP-Sign-0.09
PKGNAME=	p5-PGP-Sign-0.09
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGP

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

RUN_DEPENDS=	${PREFIX}/bin/pgp:${PORTSDIR}/security/pgp

USE_PERL5=	yes

MAN3=		PGP::Sign.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
