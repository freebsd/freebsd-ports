# New ports collection makefile for:	Mail-Box-Parser-C
# Date created:	   08 August 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Mail-Box-Parser-C
PORTVERSION=	3.006
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Parsing folders for Mail::Box with C routines

BUILD_DEPENDS=	${SITE_PERL}/Mail/Box.pm:${PORTSDIR}/mail/p5-Mail-Box
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Box::Parser::C.3

.include <bsd.port.mk>
