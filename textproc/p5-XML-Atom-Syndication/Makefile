# New ports collection makefile for:	p5-XML-Atom-Syndication
# Date created:				2003-05-23
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-Atom-Syndication
PORTVERSION=	0.901
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple lightweight client for consuming Atom syndication feeds

RUN_DEPENDS=	${SITE_PERL}/XML/Elemental.pm:${PORTSDIR}/textproc/p5-XML-Elemental \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Class/ErrorHandler.pm:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	XML::Atom::Syndication.3 \
	XML::Atom::Syndication::Category.3 \
	XML::Atom::Syndication::Content.3 \
	XML::Atom::Syndication::Entry.3 \
	XML::Atom::Syndication::Feed.3 \
	XML::Atom::Syndication::Generator.3 \
	XML::Atom::Syndication::Link.3 \
	XML::Atom::Syndication::Object.3 \
	XML::Atom::Syndication::Person.3 \
	XML::Atom::Syndication::Source.3 \
	XML::Atom::Syndication::Text.3 \
	XML::Atom::Syndication::Writer.3 \

.include <bsd.port.mk>
