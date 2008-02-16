# New ports collection makefile for:	p5-Probe-Perl
# Date created:		2008-02-14
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Probe-Perl
PORTVERSION=	0.01
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN/../by-authors/id/K/KW/KWILLIAMS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippemail@gmail.com
COMMENT=	Information about the currently running perl

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=		Probe::Perl.3

.include <bsd.port.mk>
