# New ports collection makefile for:	p5-XML-Atom-Syndication
# Date created:				2003-05-23
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-Atom-Syndication
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple lightweight client for consuming Atom syndication feeds

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Class/XPath.pm:${PORTSDIR}/devel/p5-Class-XPath \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Parser/Style/Elemental.pm:${PORTSDIR}/textproc/p5-XML-Parser-Style-Elemental

PERL_CONFIGURE=	yes

MAN3=	XML::Atom::Syndication.3 XML::Atom::Syndication::Element.3 \
	XML::Atom::Syndication::Document.3 \
	XML::Atom::Syndication::Characters.3

.include <bsd.port.mk>
