# New ports collection makefile for:	p5-CSS
# Date created:				2006/07/21
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	CSS
PORTVERSION=	1.08
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object oriented access to Cascading Style Sheets (CSS)

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent

MAN3=	CSS.3 CSS::Value.3 CSS::Parse::Compiled.3 CSS::Property.3 CSS::Parse::Heavy.3 \
	CSS::Parse::PRDGrammar.3 CSS::Style.3 CSS::Parse::Lite.3 CSS::Selector.3 \
	CSS::Adaptor::Debug.3 CSS::Adaptor::Pretty.3 CSS::Parse.3 CSS::Adaptor.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
