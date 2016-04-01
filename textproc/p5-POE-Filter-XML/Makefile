# Created by: Jeff Putsch <jdputsch@comcast.net>
# $FreeBSD$

PORTNAME=	POE-Filter-XML
PORTVERSION=	1.140700
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE Filter for parsing XML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-InsideOut>=0:devel/p5-MooseX-InsideOut \
		p5-MooseX-NonMoose>=0:devel/p5-MooseX-NonMoose \
		p5-POE>=0:devel/p5-POE \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-SAX-Base>=0:textproc/p5-XML-SAX-Base
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
