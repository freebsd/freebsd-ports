# New ports collection makefile for:	XML-Handler-YAWriter
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Handler-YAWriter
PORTVERSION=	0.23
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Yet another Perl SAX XML Writer

BUILD_DEPENDS=	${SITE_PERL}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		xmlpretty.1
MAN1PREFIX=	${PREFIX}
MAN3=		XML::Handler::YAWriter.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
