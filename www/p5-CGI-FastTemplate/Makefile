# New ports collection makefile for:	p5-CGI-FastTemplate
# Version required:			1.09
# Date created:				27 Feb 2000
# Whom:	      				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	CGI-FastTemplate-1.09
PKGNAME=	p5-CGI-FastTemplate-1.09
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		CGI::FastTemplate.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
