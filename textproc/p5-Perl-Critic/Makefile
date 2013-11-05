# Created by: ijliao
# $FreeBSD$

PORTNAME=	Perl-Critic
PORTVERSION=	1.12.1
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Critique Perl source for style and standards

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Keywords>=1.05:${PORTSDIR}/devel/p5-B-Keywords \
		p5-Config-Tiny>=2:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Email-Address>=1.88.9:${PORTSDIR}/mail/p5-Email-Address \
		p5-Exception-Class>=1.23:${PORTSDIR}/devel/p5-Exception-Class \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-List-MoreUtils>=0.19:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Pod-Spell>=0:${PORTSDIR}/textproc/p5-Pod-Spell \
		p5-PPI>=1.215:${PORTSDIR}/textproc/p5-PPI \
		p5-PPIx-Regexp>=0.027:${PORTSDIR}/textproc/p5-PPIx-Regexp \
		p5-PPIx-Utilities>=1.001:${PORTSDIR}/textproc/p5-PPIx-Utilities \
		p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
		p5-String-Format>=1.13:${PORTSDIR}/textproc/p5-String-Format \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Term-ANSIColor>=2.02:${PORTSDIR}/devel/p5-Term-ANSIColor \
		perltidy:${PORTSDIR}/devel/perltidy
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
