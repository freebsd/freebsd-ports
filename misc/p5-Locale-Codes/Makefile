# New ports collection makefile for:    p5-Locale-Codes
# Version required:			1.00
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1997/06/27 01:51:12 jfitz Exp $
#

DISTNAME=	Locale-Codes-1.00
PKGNAME=	p5-Locale-Codes-1.00
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		Locale::Country.3 Locale::Language.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
