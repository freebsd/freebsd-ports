# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Decorator
PORTVERSION=	1.65
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apply a chain of filters to text

BUILD_DEPENDS=	p5-URI-Find>=0:${PORTSDIR}/textproc/p5-URI-Find \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Text::Decorator.3 \
	Text::Decorator::Filter.3 \
	Text::Decorator::Filter::Quoted.3 \
	Text::Decorator::Filter::TTBridge.3 \
	Text::Decorator::Filter::Test.3 \
	Text::Decorator::Filter::URIFind.3 \
	Text::Decorator::Group.3 \
	Text::Decorator::Node.3

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
