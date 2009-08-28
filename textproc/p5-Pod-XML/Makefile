# Ports collection makefile for:	p5-Pod-XML
# Date created:			2006/07/11
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Pod-XML
PORTVERSION=	0.99
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to convert POD to XML

BUILD_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Test-File-Contents>=0:${PORTSDIR}/devel/p5-Test-File-Contents \
		p5-Pod-Parser>=0:${PORTSDIR}/textproc/p5-Pod-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2xml.1
MAN3=		Pod::XML.3

.include <bsd.port.mk>
