# $FreeBSD$

PORTNAME=	tls-check
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Scan a list of domains for TLS-related compliance stats

LICENSE=	ART20

MY_DEPENDS=	p5-MooseX-SimpleConfig>=0.11:devel/p5-MooseX-SimpleConfig \
		p5-Readonly>=2.01:devel/p5-Readonly \
		p5-Test-Deep>=1.120:devel/p5-Test-Deep \
		p5-Test-Differences>=0.630:devel/p5-Test-Differences \
		p5-Test-Exception>=0.43:devel/p5-Test-Exception \
		p5-Test-File>=1.44:devel/p5-Test-File \
		p5-Test-MockObject>=1.20150527:devel/p5-Test-MockObject \
		p5-Test-Pod>=1.51:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.10:devel/p5-Test-Pod-Coverage \
		p5-forks>=0.36:devel/p5-forks \
		p5-Net-IDN-Encode>=2.300:textproc/p5-Net-IDN-Encode \
		p5-Net-LibIDN>=0.12:dns/p5-Net-LibIDN \
		p5-IO-Socket-Timeout>=0.32:net/p5-IO-Socket-Timeout \
		p5-IO-All>=0.86:devel/p5-IO-All \
		p5-Log-Log4perl>=1.47:devel/p5-Log-Log4perl \
		p5-PerlIO-via-Timeout>=0.32:devel/p5-PerlIO-via-Timeout \
		p5-Test-Perl-Critic>=1.03:textproc/p5-Test-Perl-Critic \
		p5-Text-CSV_XS>=1.18:textproc/p5-Text-CSV_XS \
		p5-Test-LWP-UserAgent>=0.030:www/p5-Test-LWP-UserAgent
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5
USE_GITHUB=	yes
USE_PERL5=	modbuild
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	TLS-Check
GH_TAGNAME=	b7c2488

.include <bsd.port.mk>
