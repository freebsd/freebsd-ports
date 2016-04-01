# $FreeBSD$

PORTNAME=	Proclet
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZEBURO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimalistic Supervisor

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-Validator>0:devel/p5-Data-Validator \
	p5-File-Which>=1.09:sysutils/p5-File-Which \
	p5-Getopt-Compact-WithCmd>=0.20:devel/p5-Getopt-Compact-WithCmd \
	p5-Log-Minimal>=0.14:devel/p5-Log-Minimal \
	p5-Mouse>0:devel/p5-Mouse \
	p5-Parallel-Prefork>=0.13:devel/p5-Parallel-Prefork \
	p5-String-ShellQuote>0:textproc/p5-String-ShellQuote \
	p5-YAML-LibYAML>=0.38:textproc/p5-YAML-LibYAML \
	p5-Time-Crontab>=0.01:devel/p5-Time-Crontab
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Parallel-Scoreboard>0:devel/p5-Parallel-Scoreboard \
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Capture-Tiny>0:devel/p5-Capture-Tiny \
	p5-List-MoreUtils>0:lang/p5-List-MoreUtils

USES=	perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
