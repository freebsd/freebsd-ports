# New ports collection makefile for:	XML-Filter-SAX1toSAX2
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Filter-SAX1toSAX2
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Convert SAX1 events to SAX2

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX/Base.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/XML/SAX/Writer.pm:${PORTSDIR}/textproc/p5-XML-SAX-Writer
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Filter::SAX1toSAX2.3 XML::Filter::SAX2toSAX1.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
