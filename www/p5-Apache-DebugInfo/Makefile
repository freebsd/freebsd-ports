# New ports collection makefile for:	Apache-DebugInfo
# Date created:	   19 April 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DebugInfo
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Log various bits of per-request data

.if defined(WITH_MODPERL2)
IGNORE=		This port does not support mod_perl2
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${RUN_DEPENDS}
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::DebugInfo.3

.include <bsd.port.mk>
