# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-SKey
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Perl S/Key calculator

BUILD_DEPENDS=	p5-Digest-MD4>=0:${PORTSDIR}/security/p5-Digest-MD4 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Crypt::SKey.3

.include <bsd.port.mk>
