# New ports collection makefile for:	p5-Net-SSH-Expect
# Date created:		2007-06-30
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-SSH-Expect
PORTVERSION=	1.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SSH wrapper to execute remote commands

RUN_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Net::SSH::Expect.3

.include <bsd.port.mk>
