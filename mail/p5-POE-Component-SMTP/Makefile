# New ports collection makefile for:	POE-Component-SMTP
# Date created:	   02 June 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-SMTP
PORTVERSION=	1.6
CATEGORIES=	mail devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	SMTP Protocol Implementation

RUN_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Session/MultiDispatch.pm:${PORTSDIR}/devel/p5-POE-Session-MultiDispatch
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::SMTP.3 POE::Filter::SMTP.3

.include <bsd.port.mk>
