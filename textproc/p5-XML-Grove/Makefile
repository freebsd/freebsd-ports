# New ports collection makefile for:	XML::Grove
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	XML-Grove
PORTVERSION=	0.46.a
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/alpha/}

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Perl-style XML objects

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Data/Grove.pm:${PORTSDIR}/textproc/p5-libxml
RUN_DEPENDS=	${BUILD_DEPENDS}

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
