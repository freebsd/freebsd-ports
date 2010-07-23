# New ports collection makefile for:	XML::SAX::Writer
# Date created:		28 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX-Writer
PORTVERSION=	0.53
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	SAX2 XML Writer

BUILD_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-NamespaceSupport>=1.00:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-Filter-BufferText>=1.00:${PORTSDIR}/textproc/p5-XML-Filter-BufferText
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::SAX::Writer.3 XML::SAX::Writer::XML.3

.include <bsd.port.mk>
