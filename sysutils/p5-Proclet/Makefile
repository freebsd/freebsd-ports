# $FreeBSD$

PORTNAME=	Proclet
PORTVERSION=	0.25
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZEBURO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimalistic Supervisor

RUN_DEPENDS=	\
	p5-Data-Validator>0:${PORTSDIR}/devel/p5-Data-Validator \
	p5-File-Which>=1.09:${PORTSDIR}/sysutils/p5-File-Which \
	p5-Getopt-Compact-WithCmd>=0.20:${PORTSDIR}/devel/p5-Getopt-Compact-WithCmd \
	p5-Log-Minimal>=0.14:${PORTSDIR}/devel/p5-Log-Minimal \
	p5-Mouse>0:${PORTSDIR}/devel/p5-Mouse \
	p5-Parallel-Prefork>=0.13:${PORTSDIR}/devel/p5-Parallel-Prefork \
	p5-YAML-LibYAML>=0.38:${PORTSDIR}/textproc/p5-YAML-LibYAML
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Parallel-Scoreboard>0:${PORTSDIR}/devel/p5-Parallel-Scoreboard \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny

PERL_CONFIGURE=	yes

MAN1=	proclet.1
MAN3=	Proclet.3 \
	Proclet::Declare.3

.include <bsd.port.mk>
