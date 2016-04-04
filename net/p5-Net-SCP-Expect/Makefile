# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	Net-SCP-Expect
PORTVERSION=	0.16
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Perl5 wrapper for scp that allows passwords via Expect

BUILD_DEPENDS=	p5-Expect>=1.14:lang/p5-Expect \
		p5-Net-IPv6Addr>=0:net-mgmt/p5-Net-IPv6Addr \
		p5-Term-ReadPassword>=0.01:devel/p5-Term-ReadPassword
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
