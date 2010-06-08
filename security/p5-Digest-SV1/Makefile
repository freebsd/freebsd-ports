# Ports collection Makefile for:	p5-Digest-SV1
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-SV1
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for SV1 hash algorithm

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Digest/Haval256.pm:${PORTSDIR}/security/p5-Digest-Haval256

PERL_MODBUILD=	yes

MAN3=	Digest::SV1.3

.include <bsd.port.mk>
