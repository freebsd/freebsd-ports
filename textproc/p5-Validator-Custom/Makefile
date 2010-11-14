# New ports collection makefile for:	p5-Validator-Custom
# Date created:		2010-07-02
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	Validator-Custom
PORTVERSION=	0.1407
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validator::Custom for simple data validation

BUILD_DEPENDS=	p5-Object-Simple>=3.0302:${PORTSDIR}/devel/p5-Object-Simple
RUN_DEPENDS=	p5-Object-Simple>=3.0302:${PORTSDIR}/devel/p5-Object-Simple

PERL_CONFIGURE=	yes

MAN3=		Validator::Custom.3 \
		Validator::Custom::Basic::Constraints.3 \
		Validator::Custom::Guides.3 \
		Validator::Custom::Guides::Ja.3 \
		Validator::Custom::Result.3

.include <bsd.port.mk>
