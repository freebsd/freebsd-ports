# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Adler32
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension for Adler32 hash algorithm

BUILD_DEPENDS=	p5-Digest>=0:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Digest::Adler32.3

NO_STAGE=	yes
.include <bsd.port.mk>
