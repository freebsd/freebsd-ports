# New ports collection makefile for:	p5-PGP
# Version required:			0.3a
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.9 1997/09/14 02:55:16 jfitz Exp $
#

DISTNAME=	PGP-0.3a
PKGNAME=	p5-PGP-0.3a
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGP

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	pgp:${PORTSDIR}/security/pgp

USE_PERL5=	YES

MAN3=		PGP::Pipe.3
MANPREFIX=	${PREFIX}/lib/perl5

pre-configure:
		@${CP} ${WRKSRC}/PGP/Pipe.pm ${WRKSRC}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
