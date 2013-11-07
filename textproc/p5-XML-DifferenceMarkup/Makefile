# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-DifferenceMarkup
PORTVERSION=	0.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This module implements an XML diff producing XML output

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
