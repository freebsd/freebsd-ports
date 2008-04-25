# New ports collection makefile for:	Regexp-Common-Email-Address
# Date created:	   25 Apr 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Regexp-Common-Email-Address
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Regex pattern for Email Addresses

BUILD_DEPENDS=	${SITE_PERL}/Email/Address.pm:${PORTSDIR}/mail/p5-Email-Address \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Regexp::Common::Email::Address.3

.include <bsd.port.mk>
