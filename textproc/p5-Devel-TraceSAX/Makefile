# New ports collection makefile for:    devel/p5-Devel-TraceSAX
# Date created:                         Dec  9 2005
# Whom:                                 Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-TraceSAX
PORTVERSION=	0.021
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Trace SAX events

BUILD_DEPENDS=	p5-Devel-TraceCalls>=0.03:${PORTSDIR}/devel/p5-Devel-TraceCalls \
		p5-XML-SAX-Machines>=0:${PORTSDIR}/textproc/p5-XML-SAX-Machines
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Devel::TraceSAX.3

.include <bsd.port.mk>
