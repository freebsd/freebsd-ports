# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Pod-ProjectDocs
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generates CPAN like pod pages

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-JSON>=2.04:converters/p5-JSON \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
