# New ports collection makefile for:	p5-Cisco-Reconfig
# Date created:		2006-08-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Cisco-Reconfig
PORTVERSION=	0.9
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Parse and generate Cisco configuration files

RUN_DEPENDS=	${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Cisco::Reconfig.3

.include <bsd.port.mk>
