# New ports collection makefile for:	CGI-ArgChecker
# Date created:				Mon Jan  1 11:01:44 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	CGI-ArgChecker
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/String/Checker.pm:${PORTSDIR}/devel/p5-String-Checker
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		CGI::ArgChecker.3

.include <bsd.port.mk>
