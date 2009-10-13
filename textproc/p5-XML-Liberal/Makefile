# New ports collection makefile for:	p5-XML-Liberal
# Date created:		2006-07-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Liberal
PORTVERSION=	0.22
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Super liberal XML parser that parses broken XML

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-HTML-Entities-Numbered>=0.04:${PORTSDIR}/textproc/p5-HTML-Entities-Numbered \
		p5-Module-Pluggable-Fast>=0.16:${PORTSDIR}/devel/p5-Module-Pluggable-Fast \
		p5-XML-LibXML>=1.58:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Liberal.3

.include <bsd.port.mk>
