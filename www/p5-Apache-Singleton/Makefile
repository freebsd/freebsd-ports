# New ports collection makefile for:	p5-Apache-Singleton
# Date created:		2005-02-28
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	Apache-Singleton
PORTVERSION=	0.07
CATEGORIES=	www devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Singleton class for mod_perl

RUN_DEPENDS=${SITE_PERL}/Class/Singleton.pm:${PORTSDIR}/devel/p5-Class-Singleton

PERL_CONFIGURE=	yes

MAN3=	Apache::Singleton.3 \
	Apache::Singleton::Process.3 \
	Apache::Singleton::Request.3

.include <bsd.port.mk>
