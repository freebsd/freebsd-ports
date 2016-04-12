# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-SAX-Writer
PORTVERSION=	0.56
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SAX2 XML Writer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-SAX-Base>=1.01:textproc/p5-XML-SAX-Base \
		p5-XML-NamespaceSupport>=1.00:textproc/p5-XML-NamespaceSupport \
		p5-XML-Filter-BufferText>=1.00:textproc/p5-XML-Filter-BufferText
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
