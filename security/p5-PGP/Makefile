# New ports collection makefile for:	p5-PGP
# Version required:			0.2alpha
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:59:26 jfitz Exp $
#

DISTNAME=	PGP-0.2alpha
PKGNAME=	p5-PGP-0.2a
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGP

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		pgp:${PORTSDIR}/security/pgp
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_WRKSUBDIR=	YES
MAN3=		PGP.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
