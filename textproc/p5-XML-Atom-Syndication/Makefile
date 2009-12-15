# New ports collection makefile for:	p5-XML-Atom-Syndication
# Date created:				2003-05-23
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-Atom-Syndication
PORTVERSION=	0.94.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple lightweight client for consuming Atom syndication feeds

RUN_DEPENDS=	p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-XML-Elemental>=2:${PORTSDIR}/textproc/p5-XML-Elemental \
		p5-XML-Writer>=0.6:${PORTSDIR}/textproc/p5-XML-Writer
BUILD_DEPENDS=	${RUN_DEPENDS}

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
	XML::Atom::Syndication::Writer.3

.include <bsd.port.mk>
