# New ports collection makefile for:	Text::Template
# Date created:		Thu Oct 28 01:58:13 EDT 1999
# Whom:			Bill "I hate Perl" Fumerola
#
# $FreeBSD$
#

PORTNAME=	p5-Text-Template
PORTVERSION= 	1.20
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.plover.com/~mjd/perl/Template/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
DISTNAME=	Text-Template-1.20

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	YES

MAN3=		Text::Template.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
