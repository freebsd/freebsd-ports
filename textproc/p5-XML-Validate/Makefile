# New ports collection makefile for:	textproc/p5-XML-Validate
# Date created:				10 November 2009
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Validate
PORTVERSION=	1.025
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	An XML validator factory

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML

PERL_CONFIGURE=	yes

MAN1=		validxml.pl.1
MAN3=		XML::Validate.3 XML::Validate::Base.3 \
		XML::Validate::LibXML.3 XML::Validate::MSXML.3 \
		XML::Validate::Xerces.3

.include <bsd.port.mk>
