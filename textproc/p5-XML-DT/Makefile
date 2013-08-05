# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	XML-DT
PORTVERSION=	0.63
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for down translation of XML to strings

BUILD_DEPENDS=	p5-XML-LibXML>=1.54:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-libwww>=1.35:${PORTSDIR}/www/p5-libwww \
		p5-XML-DTDParser>=2.00:${PORTSDIR}/textproc/p5-XML-DTDParser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		mkdtskel.1 mkdtdskel.1 mkxmltype.1
MAN3=		XML::DT.3

.include <bsd.port.mk>
