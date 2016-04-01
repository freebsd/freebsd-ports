# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	Bot-Training-StarCraft
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AVAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide starcraft.trn via Bot::Training

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.03:devel/p5-File-ShareDir-Install
RUN_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-Bot-Training>=0:misc/p5-Bot-Training

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
