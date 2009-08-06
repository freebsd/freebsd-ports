# New ports collection makefile for:	p5-MARC-XML
# Date created:				6 August 2009
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MARC-XML
PORTVERSION=	0.92
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	An extension to the MARC-Record distribution for working with XML data

BUILD_DEPENDS=	${SITE_PERL}/MARC/Record.pm:${PORTSDIR}/textproc/p5-MARC-Record \
		${SITE_PERL}/MARC/Charset.pm:${PORTSDIR}/textproc/p5-MARC-Charset \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=		marc2xml.1 xml2marc.1
MAN3=		MARC::File::SAX.3 MARC::File::XML.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
