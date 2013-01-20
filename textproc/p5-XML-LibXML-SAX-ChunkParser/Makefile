# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	XML-LibXML-SAX-ChunkParser
PORTVERSION=	0.00006
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Parse XML chunks via LibXML SAX

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::LibXML::SAX::ChunkParser.3

.include <bsd.port.mk>
