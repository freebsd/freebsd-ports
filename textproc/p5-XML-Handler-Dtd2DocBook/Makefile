# New ports collection makefile for:	XML-Handler-Dtd2DocBook
# Date created:	   			2006/07/11
# Whom:		   			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML-Handler-Dtd2DocBook
PORTVERSION=	0.41
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate a DocBook documentation from a DTD

BUILD_DEPENDS=	${SITE_PERL}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml \
		p5-XML-Handler-Dtd2Html>=0.41:${PORTSDIR}/textproc/p5-XML-Handler-Dtd2Html
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		dtd2db.pl.1
MAN3=		XML::Handler::Dtd2DocBook.3

.include <bsd.port.mk>
