# $FreeBSD$

PORTNAME=	Proclet
PORTVERSION=	0.21
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZEBURO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimalistic Supervisor

RUN_DEPENDS=	\
	p5-Data-Validator>0:${PORTSDIR}/devel/p5-Data-Validator \
	p5-Getopt-Compact-WithCmd>=0.2:${PORTSDIR}/devel/p5-Getopt-Compact-WithCmd \
	p5-Log-Minimal>=0.14:${PORTSDIR}/devel/p5-Log-Minimal \
	p5-Mouse>0:${PORTSDIR}/devel/p5-Mouse \
	p5-Parallel-Prefork>=0.13:${PORTSDIR}/devel/p5-Parallel-Prefork \
	p5-YAML-LibYAML>=0.38:${PORTSDIR}/textproc/p5-YAML-LibYAML
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Parallel-Scoreboard>0:${PORTSDIR}/devel/p5-Parallel-Scoreboard

PERL_CONFIGURE=	yes

MAN1=	proclet.1
MAN3=	Proclet.3 \
	Proclet::Declare.3

.include <bsd.port.mk>
