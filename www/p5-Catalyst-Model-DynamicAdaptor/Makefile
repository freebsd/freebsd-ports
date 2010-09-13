# New ports collection makefile for:	p5-Catalyst-Model-DynamicAdaptor
# Date created:		2008-06-11
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-DynamicAdaptor
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/T/TO/TOMYHERO/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamically load adaptor modules

RUN_DEPENDS=	${SITE_PERL}/Catalyst/Runtime.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/Module/Recursive/Require.pm:${PORTSDIR}/devel/p5-Module-Recursive-Require \
		${SITE_PERL}/Test/Spelling.pm:${PORTSDIR}/devel/p5-Test-Spelling

PERL_CONFIGURE=	Yes
MAN3=	Catalyst::Model::DynamicAdaptor.3

.include <bsd.port.mk>
