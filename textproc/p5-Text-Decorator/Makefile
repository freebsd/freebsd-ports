# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Decorator
PORTVERSION=	1.65
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Apply a chain of filters to text

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-URI-Find>=0:textproc/p5-URI-Find
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
