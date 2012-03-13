# New ports collection makefile for:	p5-Bash-Completion
# Date created:		2011-10-23
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bash-Completion
PORTVERSION=	0.008
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MELO
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensible system to provide bash completion

BUILD_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Module-Load>=0.22:${PORTSDIR}/devel/p5-Module-Load
RUN_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Module-Load>=0.22:${PORTSDIR}/devel/p5-Module-Load

TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN1=		bash-complete.1 \
		setup-bash-complete.1
MAN3=		App::BashComplete.3 \
		Bash::Completion.3 \
		Bash::Completion::Plugin.3 \
		Bash::Completion::Plugins::BashComplete.3 \
		Bash::Completion::Plugins::Perldoc.3 \
		Bash::Completion::Request.3 \
		Bash::Completion::Utils.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
