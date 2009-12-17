# New ports collection makefile for:	p5-XML-Atom
# Date created:				Dec 27 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl5 modules for Atom feed and API implementation

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/LWP/Authen/Wsse.pm:${PORTSDIR}/www/p5-LWP-Authen-Wsse \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-XML-LibXML>=1.54:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.5+

MAN3=		XML::Atom.3 \
		XML::Atom::Client.3 \
		XML::Atom::Entry.3 \
		XML::Atom::Feed.3 \
		XML::Atom::Person.3 \
		XML::Atom::Server.3 \
		XML::Atom::Util.3

.include <bsd.port.mk>
