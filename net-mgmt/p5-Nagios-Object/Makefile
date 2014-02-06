# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Nagios-Object
PORTVERSION=	0.21.18
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl objects to represent Nagios configuration

BUILD_DEPENDS=	p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Module-Build>=0.3607:${PORTSDIR}/devel/p5-Module-Build \
		p5-Data-Dumper>=2.126:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-List-Compare>=0.37:${PORTSDIR}/misc/p5-List-Compare \
		p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-NoWarnings>=1.01:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
