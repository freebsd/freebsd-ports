# New ports collection makefile for:	p5-News-Newsrc
# Version required:	1.05
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id$
#

DISTNAME=	News-Newsrc-1.06
PKGNAME=	p5-News-Newsrc-1.06
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Set/IntSpan.pm:${PORTSDIR}/math/p5-Set-IntSpan

USE_PERL5=	yes

MAN3=		News::Newsrc.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
