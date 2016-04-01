# Created by: hrs@FreeBSD.org
# $FreeBSD$

PORTNAME=	PodToHTML
PORTVERSION=	0.08
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Generating HTML from several files containing POD documentation

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Format>=0:textproc/p5-HTML-Format
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
