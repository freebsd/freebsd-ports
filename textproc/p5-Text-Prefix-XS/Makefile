# New ports collection makefile for:	p5-Text-Prefix-XS
# Date created:		2011-12-24
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Prefix-XS
PORTVERSION=	0.15
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast prefix searching

BUILD_DEPENDS=	p5-Digest-SHA1>=1:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	p5-Digest-SHA1>=1:${PORTSDIR}/security/p5-Digest-SHA1

TEST_DEPENDS=	p5-Test-Deep>=0.108:${PORTSDIR}/devel/p5-Test-Deep

USE_PERL5=	configure
USES=		perl5

MAN3=		Text::Prefix::XS.3

.include <bsd.port.mk>
