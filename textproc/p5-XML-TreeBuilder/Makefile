# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-TreeBuilder
PORTVERSION=	5.4
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl module to make XML document trees

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Tagset>=3.02:www/p5-HTML-Tagset \
		p5-HTML-Tree>=4.1:www/p5-HTML-Tree \
		p5-XML-Catalog>=1.0.2:textproc/p5-XML-Catalog \
		p5-XML-Parser>0:textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
