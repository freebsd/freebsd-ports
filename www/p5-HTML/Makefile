# New ports collection makefile for:	p5-HTML
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML
PORTVERSION=	0.6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module for writing HTML documents

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/HTML/
		@ ${INSTALL_DATA} ${WRKDIR}/HTML/Base.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/HTML/
		@ ${INSTALL_DATA} ${WRKDIR}/html_base.pod ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/

.include <bsd.port.mk>
