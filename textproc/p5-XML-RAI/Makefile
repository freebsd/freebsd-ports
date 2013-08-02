# Created by: arved
# $FreeBSD$

PORTNAME=	XML-RAI
PORTVERSION=	1.30.31
PORTEPOCH=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([0-9]+)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RSS Abstraction Interface

RUN_DEPENDS=	p5-XML-RSS-Parser>=0:${PORTSDIR}/textproc/p5-XML-RSS-Parser \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	XML::RAI.3 \
	XML::RAI::Channel.3 \
	XML::RAI::Image.3 \
	XML::RAI::Item.3 \
	XML::RAI::Object.3

.include <bsd.port.mk>
