# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-WSDL
PORTVERSION=	0.063
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create WSDL documents from (extended) pod

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Stringy>=2.110:devel/p5-IO-Stringy \
		p5-XML-Writer>=0.531:textproc/p5-XML-Writer \
		p5-XML-XPath>=1.13:textproc/p5-XML-XPath

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
