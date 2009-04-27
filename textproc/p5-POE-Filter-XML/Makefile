# ex:ts=8
# New ports collection makefile for:	POE::Filter::XML
# Date created:		Aug 19, 2001
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-XML
PORTVERSION=	0.38
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE Filter for parsing XML

RUN_DEPENDS=	p5-POE>=1.003:${PORTSDIR}/devel/p5-POE \
		p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-SAX>=0.16:${PORTSDIR}/textproc/p5-XML-SAX
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.10.0+

MAN3=		POE::Filter::XML.3 \
		POE::Filter::XML::NS.3 \
		POE::Filter::XML::Node.3 \
		POE::Filter::XML::Utils.3

.include <bsd.port.mk>
