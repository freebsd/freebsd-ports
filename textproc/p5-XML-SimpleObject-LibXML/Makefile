# New ports collection makefile for:	p5-XML-SimpleObject-LibXML
# Date created:				02 September 2003
# Whom:	      				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-SimpleObject-LibXML
PORTVERSION=	0.60
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A simple(r) object representation of an XML::LibXML DOM object

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-SimpleObject>=0:${PORTSDIR}/textproc/p5-XML-SimpleObject

PERL_CONFIGURE=	YES

MAN3=		XML::SimpleObject::LibXML.3

.include <bsd.port.mk>
