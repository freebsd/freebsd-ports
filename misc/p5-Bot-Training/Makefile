# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	Bot-Training
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AVAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Plain text training material for bots like Hailo and MegaHAL

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Dir-Self>=0:${PORTSDIR}/devel/p5-Dir-Self \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Moose>=0.82:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-Getopt>=0:${PORTSDIR}/devel/p5-MouseX-Getopt \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	bot-training.1
MAN3=	Bot::Training.3

NO_STAGE=	yes
.include <bsd.port.mk>
