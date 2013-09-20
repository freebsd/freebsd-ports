# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	XML-XUpdate-LibXML
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Simple implementation of XUpdate format based on and XML::LibXML

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-LibXML-Iterator>=0:${PORTSDIR}/textproc/p5-XML-LibXML-Iterator
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		xupdate.1
MAN3=		XML::Normalize::LibXML.3 XML::XUpdate::LibXML.3

NO_STAGE=	yes
.include <bsd.port.mk>
