# New ports collection makefile for:	Apache-DebugInfo
# Date created:	   19 April 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DebugInfo
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Log various bits of per-request data

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

# Changed to apache13 exclusive, else apache13 ports
# are broken if apache22 is set as default
USE_APACHE=	13
.include <bsd.port.pre.mk>

.if defined(WITH_MODPERL2) || ${APACHE_VERSION} > 13
IGNORE=		this port does not support mod_perl2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS+=	${RUN_DEPENDS}
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::DebugInfo.3

.include <bsd.port.post.mk>
