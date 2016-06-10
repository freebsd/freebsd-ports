# $FreeBSD$

PORTNAME=	Net-Abuse-Utils-Spamhaus
PORTVERSION=	0.09
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Routines useful for checking data against the spamhaus blacklists

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-DNS>=0.72:dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
