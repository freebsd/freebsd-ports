# $FreeBSD$

PORTNAME=	tls-check
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=v
DISTVERSIONSUFFIX=-Release
PORTREVISION=	6
CATEGORIES=	security

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Scan a list of domains for TLS-related compliance stats

LICENSE=	ART20

MY_DEPENDS=	p5-Class-CSV>=1.03:textproc/p5-Class-CSV \
		p5-File-HomeDir>=1.00:devel/p5-File-HomeDir \
		p5-File-ShareDir>=1.102:devel/p5-File-ShareDir \
		p5-IO-All>=0.86:devel/p5-IO-All \
		p5-IO-Socket-Timeout>=0.32:net/p5-IO-Socket-Timeout \
		p5-IPC-Run>=0.94:devel/p5-IPC-Run \
		p5-Log-Log4perl>=1.47:devel/p5-Log-Log4perl \
		p5-LWP-Protocol-https>=6.06:www/p5-LWP-Protocol-https \
		p5-MooseX-SimpleConfig>=0.11:devel/p5-MooseX-SimpleConfig \
		p5-MooseX-Getopt>=0.68:devel/p5-MooseX-Getopt \
		p5-Net-DNS>=1.05:dns/p5-Net-DNS \
		p5-Net-IDN-Encode>=2.300:textproc/p5-Net-IDN-Encode \
		p5-Net-LibIDN>=0.12:dns/p5-Net-LibIDN \
		p5-Parallel-ForkManager>=1.18:devel/p5-Parallel-ForkManager \
		p5-PerlIO-via-Timeout>=0.32:devel/p5-PerlIO-via-Timeout \
		p5-Readonly>=2.01:devel/p5-Readonly \
		p5-Text-CSV_XS>=1.18:textproc/p5-Text-CSV_XS
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=1.120:devel/p5-Test-Deep \
		p5-Test-Differences>=0.630:devel/p5-Test-Differences \
		p5-Test-Exception>=0.43:devel/p5-Test-Exception \
		p5-Test-File>=1.44:devel/p5-Test-File \
		p5-Test-LWP-UserAgent>=0.030:www/p5-Test-LWP-UserAgent \
		p5-Test-MockObject>=1.20150527:devel/p5-Test-MockObject \
		p5-Test-Perl-Critic>=1.03:textproc/p5-Test-Perl-Critic \
		p5-Test-Pod-Coverage>=1.10:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=1.51:devel/p5-Test-Pod \
		p5-Text-CSV_XS>=1.18:textproc/p5-Text-CSV_XS

USES=		perl5
USE_GITHUB=	yes
USE_PERL5=	modbuild
GH_PROJECT=	TLS-Check
GH_TAGNAME=	cd2e654

.include <bsd.port.mk>
