# New ports collection makefile for:	p5-Emplacken
# Date created:		2011-02-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Emplacken
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DR/DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Manage multiple plack apps with a directory of config files

RUN_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-File-Pid>=0:${PORTSDIR}/devel/p5-File-Pid \
		p5-List-AllUtils>=0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-MooseX-Types-Perl>=0:${PORTSDIR}/devel/p5-MooseX-Types-Perl \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-autodie>=0:${PORTSDIR}/devel/p5-autodie \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

PERL_CONFIGURE=	yes

MAN3=		Emplacken.3 \
		Emplacken::Types.3

.include <bsd.port.mk>
