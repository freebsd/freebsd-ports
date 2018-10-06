# Created by: arved
# $FreeBSD$

PORTNAME=	XML-Elemental
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic classes for simplistic and perlish handling of XML data

LICENSE=	ART10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Task-Weaken>=1.02:devel/p5-Task-Weaken \
		p5-XML-SAX>=0:textproc/p5-XML-SAX

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
