# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-SV1
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Perl extension for SV1 hash algorithm

BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Digest-Haval256>=0:${PORTSDIR}/security/p5-Digest-Haval256

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Digest::SV1.3

NO_STAGE=	yes
.include <bsd.port.mk>
