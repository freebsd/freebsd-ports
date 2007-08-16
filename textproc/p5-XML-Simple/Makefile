# New ports collection makefile for:	p5-XML-Simple
# Date created:				October 10th 2000
# Whom:	      				Andrew <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	XML-Simple
PORTVERSION=	2.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Trivial API for reading and writing XML (esp config files)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
    		${SITE_PERL}/XML/SAX/Expat.pm:${PORTSDIR}/textproc/p5-XML-SAX-Expat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		XML::Simple.3 XML::Simple::FAQ.3

.include <bsd.port.mk>
