# New ports collection makefile for:	p5-XML-LibXML-SAX-ChunkParser
# Date created:		2011-03-07
# Whom:			<ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML-SAX-ChunkParser
PORTVERSION=	0.00005
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse XML chunks via LibXML SAX

BUILD_DEPENDS=	p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX

PERL_CONFIGURE=	yes

MAN3=		XML::LibXML::SAX::ChunkParser.3

.include <bsd.port.mk>
