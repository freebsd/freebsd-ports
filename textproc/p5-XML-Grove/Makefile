# New ports collection makefile for:	XML::Grove
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	XML-Grove
DISTVERSION=	0.46alpha
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl-style XML objects

RUN_DEPENDS=	p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml

PERL_CONFIGURE=	yes

MAN3=	XML::DOM-ecmascript.3 \
	XML::Grove.3 \
	XML::Grove::AsCanonXML.3 \
	XML::Grove::AsString.3 \
	XML::Grove::Builder.3 \
	XML::Grove::Factory.3 \
	XML::Grove::IDs.3 \
	XML::Grove::Path.3 \
	XML::Grove::PerlSAX.3 \
	XML::Grove::Sub.3 \
	XML::Grove::Subst.3 \
	XML::Grove::XPointer.3

.include <bsd.port.mk>
