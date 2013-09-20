# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MARC-XML
PORTVERSION=	1.0.1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	An extension to the MARC-Record distribution for working with XML data

BUILD_DEPENDS=	p5-MARC-Record>=2:${PORTSDIR}/textproc/p5-MARC-Record \
		p5-MARC-Charset>=0.98:${PORTSDIR}/textproc/p5-MARC-Charset \
		p5-XML-SAX>=0.12:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN1=		marc2xml.1 xml2marc.1
MAN3=		MARC::File::XML.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
