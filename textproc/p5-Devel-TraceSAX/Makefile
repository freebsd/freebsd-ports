# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-TraceSAX
PORTVERSION=	0.021
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Trace SAX events

BUILD_DEPENDS=	p5-Devel-TraceCalls>=0.03:devel/p5-Devel-TraceCalls \
		p5-XML-SAX-Machines>=0:textproc/p5-XML-SAX-Machines
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
