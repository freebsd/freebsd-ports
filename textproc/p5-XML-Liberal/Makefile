# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-Liberal
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Super liberal XML parser that parses broken XML

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Tagset>=0:www/p5-HTML-Tagset \
		p5-Module-Pluggable-Fast>=0.16:devel/p5-Module-Pluggable-Fast \
		p5-XML-LibXML>=1.58:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
