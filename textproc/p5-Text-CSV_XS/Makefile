# New ports collection makefile for:    Text::CSV_XS
# Version required:     0.*
# Date created:         Fri Nov 19 03:11:08 MSK 1999
# Whom:                 Ache
#
# $FreeBSD$
#

DISTNAME=       Text-CSV_XS-0.20
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text

MAINTAINER=     ache@FreeBSD.org

USE_PERL5=	YES

MAN3=           Text::CSV_XS.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
