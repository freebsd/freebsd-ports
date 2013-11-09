# Created by: gugu
# $FreeBSD$

PORTNAME=	HTML-FormHandler
PORTVERSION=	0.40053
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GSHANK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Form handler written in Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-Data-Clone>=0:${PORTSDIR}/devel/p5-Data-Clone \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-File-ShareDir-Install>=0.3:${PORTSDIR}/devel/p5-File-ShareDir-Install \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-List-AllUtils>=0.07:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Locale-Maketext>=1.09:${PORTSDIR}/devel/p5-Locale-Maketext \
		p5-Moose>=2.0007:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0.16:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types-Common>=0:${PORTSDIR}/devel/p5-MooseX-Types-Common \
		p5-MooseX-Types-LoadableClass>=0.006:${PORTSDIR}/devel/p5-MooseX-Types-LoadableClass \
		p5-MooseX-Types>=0.20:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
