# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Filter-Reindent
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reformats whitespace for pretty printing XML

RUN_DEPENDS=	p5-XML-Filter-DetectWS>=0:${PORTSDIR}/textproc/p5-XML-Filter-DetectWS
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::Filter::Reindent.3

.include <bsd.port.mk>
