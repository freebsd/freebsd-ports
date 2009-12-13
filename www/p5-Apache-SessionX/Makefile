# New ports collection makefile for:	p5-Apache-SessionX
# Date created:				01 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-SessionX
PORTVERSION=	2.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An extented persistence framework for session data

BUILD_DEPENDS=	${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Apache::SessionX.3 \
	Apache::SessionX::Generate::MD5.3

PERL_CONFIGURE=	yes
IS_INTERACTIVE=	yes

.include <bsd.port.mk>
