# Ports collection makefile for:        p5-Catalyst-Plugin-DateTime
# Date created:                 2010-12-27
# Whom:                         michael@fun-box.ru
# $FreeBSD$

PORTNAME=       Catalyst-Plugin-DateTime
PORTVERSION=    0.03
CATEGORIES=     www perl5
MASTER_SITES=   CPAN
PKGNAMEPREFIX=  p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=     michael@fun-box.ru
COMMENT=        DateTime support for Catalyst

RUN_DEPENDS=    p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS=  ${RUN_DEPENDS}

PERL_CONFIGURE= YES

MAN3=   Catalyst::Plugin::DateTime.3

.include <bsd.port.mk>
