# New ports collection makefile for:	p5-PGP
# Version required:			0.2alpha
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/05/24 13:17:14 jfitz Exp $
#

DISTNAME=	PGP-0.2alpha
PKGNAME=	p5-PGP-0.2a
CATEGORIES=	security perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITES=	
MASTER_SITE_SUBDIR=	PGP

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5 \
		pgp:${PORTSDIR}/security/pgp
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

NO_WRKSUBDIR=	YES
MAN3=		PGP.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
