# New ports collection makefile for:	Orchard::Perl
# Date created:		22 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Orchard-Perl
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	orchard
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	orchard.0:${PORTSDIR}/textproc/orchard-c

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
