# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Nagios-Object
PORTVERSION=	0.21.18
PORTREVISION=	4
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl objects to represent Nagios configuration

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Module-Build>=0.3607:devel/p5-Module-Build \
		p5-List-Compare>=0.37:misc/p5-List-Compare \
		p5-Test-NoWarnings>=1.01:devel/p5-Test-NoWarnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
