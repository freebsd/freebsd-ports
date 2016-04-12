# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Markapl
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Markup as Perl

LICENSE=	MIT

BUILD_DEPENDS=	p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-HTML-Lint>=0:www/p5-HTML-Lint \
		p5-B-Hooks-EndOfScope>=0.05:devel/p5-B-Hooks-EndOfScope \
		p5-String-BufferStack>=1.15:textproc/p5-String-BufferStack \
		p5-Devel-Declare>=0:devel/p5-Devel-Declare
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
