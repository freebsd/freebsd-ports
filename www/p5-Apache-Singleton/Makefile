# New ports collection makefile for:	p5-Apache-Singleton
# Date created:		2005-02-28
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	Apache-Singleton
PORTVERSION=	0.11
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Singleton class for mod_perl

RUN_DEPENDS=p5-Class-Singleton>=0:${PORTSDIR}/devel/p5-Class-Singleton

PERL_CONFIGURE=	yes

MAN3=	Apache::Singleton.3 \
	Apache::Singleton::Process.3 \
	Apache::Singleton::Request.3

.include <bsd.port.mk>
