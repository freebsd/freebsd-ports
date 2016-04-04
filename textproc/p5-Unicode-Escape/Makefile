# Created by: Vadim Vatlin
# $FreeBSD$

PORTNAME=	Unicode-Escape
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Escape and unescape Unicode characters other than ASCII

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Unicode-String>=0:converters/p5-Unicode-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
