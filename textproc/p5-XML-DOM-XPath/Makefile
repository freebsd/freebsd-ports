# Created by: Mauricio Herrera Cuadra <mauricio@arareko.net>
# $FreeBSD$

PORTNAME=	XML-DOM-XPath
PORTVERSION=	0.14
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mauricio@arareko.net
COMMENT=	Adds XPath support to XML::DOM, using XML::XPath engine

RUN_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-XML-XPathEngine>=0:${PORTSDIR}/textproc/p5-XML-XPathEngine

USES=		perl5
USE_PERL5=	configure

MAN3=	XML::DOM::XPath.3

NO_STAGE=	yes
.include <bsd.port.mk>
