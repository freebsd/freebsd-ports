# New ports collection makefile for:	p5-XML-XML2JSON
# Date created:		2011-07-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XML2JSON
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert XML into JSON (and back again) using XML::LibXML

RUN_DEPENDS=	p5-XML-LibXML>=1.59:${PORTSDIR}/textproc/p5-XML-LibXML

# the order of options follows the search order of JSON module by XML::XML2JSON
OPTIONS=	JSON_SYCK	"Use JSON::Syck" on \
		JSON_XS		"Use JSON::XS" off \
		JSON		"Use JSON" off \
		JSON_DWIW	"Use JSON::DWIW" off

PERL_CONFIGURE=	yes

MAN3=		XML::XML2JSON.3

.include <bsd.port.options.mk>

.if defined(WITHOUT_JSON_SYCK) && !defined(WITH_JSON_XS) && !defined(WITH_JSON) && !defined(WITH_JSON_DWIW)
IGNORE=		You must choose at least one JSON module.
.endif

.if !defined(WITHOUT_JSON_SYCK)
RUN_DEPENDS+=	p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
.endif

.if defined(WITH_JSON_XS)
RUN_DEPENDS+=	p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS
.endif

.if defined(WITH_JSON)
RUN_DEPENDS+=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON
.endif

.if defined(WITH_JSON_)
RUN_DEPENDS+=	p5-JSON-DWIW>=0:${PORTSDIR}/converters/p5-JSON-DWIW
.endif

.include <bsd.port.mk>
