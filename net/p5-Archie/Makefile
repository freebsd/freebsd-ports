# New ports collection makefile for:	p5-Archie
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Archie
PORTVERSION=	1.5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Archie
DISTNAME=	perl_archie.${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to make Archie queries via Prospero requests

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
		@ ${INSTALL_DATA} ${WRKDIR}/Archie.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/
		@ ${INSTALL_SCRIPT} ${WRKDIR}/archie_gateway ${PREFIX}/bin/

.include <bsd.port.mk>
