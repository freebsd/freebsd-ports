# New ports collection makefile for:	p5-CGI-Minimal
# Date created:				26th December 2000
# Whom:	      				Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Minimal
PORTVERSION= 	1.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes

MAN3=		CGI::Minimal.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
