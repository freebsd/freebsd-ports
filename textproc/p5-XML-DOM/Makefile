# $FreeBSD$

PORTNAME=	XML-DOM
PORTVERSION=	1.44
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for building DOM Level 1 compliant document structures

RUN_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-libxml>=0:textproc/p5-libxml \
		p5-libwww>=0:www/p5-libwww \
		p5-XML-RegExp>=0:textproc/p5-XML-RegExp
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
