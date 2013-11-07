# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	HTML-TreeBuilder-XPath
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Add XPath support to HTML::TreeBuilder

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-XML-XPathEngine>=0.12:${PORTSDIR}/textproc/p5-XML-XPathEngine
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
