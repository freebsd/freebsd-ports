# New ports collection makefile for:	XML::Filter::Reindent
# Date created:		13 Mar 2002
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Filter-Reindent
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Reformats whitespace for pretty printing XML

RUN_DEPENDS=	${SITE_PERL}/XML/Filter/DetectWS.pm:${PORTSDIR}/textproc/p5-XML-Filter-DetectWS
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Filter::Reindent.3

.include <bsd.port.mk>
