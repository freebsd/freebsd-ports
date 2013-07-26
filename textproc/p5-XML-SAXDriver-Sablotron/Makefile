# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-SAXDriver-Sablotron
PORTVERSION=	0.30
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl SAX driver for the Sablotron XSLT

BUILD_DEPENDS=	p5-XML-Sablotron>=0:${PORTSDIR}/textproc/p5-XML-Sablotron \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::SAXDriver::Sablotron.3

pre-patch:
	@${REINPLACE_CMD} -i '' '/use warnings/d' ${WRKSRC}/Sablotron.pm

.include <bsd.port.mk>
