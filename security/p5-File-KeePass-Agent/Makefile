# Created by: Cy Schubert <cy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-KeePass-Agent
PORTVERSION=	2.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Application agent for working with File::KeePass objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-KeePass>=2.03:${PORTSDIR}/security/p5-File-KeePass \
		p5-Crypt-Rijndael>=1.0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-MIME-Base64>=1.0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		fkp-agent.1
MAN3=		File::KeePass::Agent.3 \
		File::KeePass::Agent::linux.3 \
		File::KeePass::Agent::unix.3

.include <bsd.port.mk>
