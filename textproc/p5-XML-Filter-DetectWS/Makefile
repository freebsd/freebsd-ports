# New ports collection makefile for:	XML::Filter::DetectWS
# Date created:		13 Mar 2002
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Filter-DetectWS
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A PerlSAX filter that detects ignorable whitespace

RUN_DEPENDS=	${SITE_PERL}/XML/Filter/SAXT.pm:${PORTSDIR}/textproc/p5-XML-Filter-SAXT
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Filter::DetectWS.3

.include <bsd.port.mk>
