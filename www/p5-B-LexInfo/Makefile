# New ports collection makefile for:	B-LexInfo
# Date Created:				08 Oct 2003
# Whom:					Trevor S. Cornpropst <tcornpropst@cox.net>
#
# $FreeBSD$
#

PORTNAME=	B-LexInfo
PORTVERSION=	0.02
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show information about subroutine lexical variables

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2011-11-01

# Changed to apache13 exclusive, else apache13 ports
# are broken if apache22 is set as default
USE_APACHE=	13

.include <bsd.port.pre.mk>

.if defined(WITH_MODPERL2) || ${APACHE_VERSION} > 13
IGNORE=		broken due the new mod_perl2 API
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		B::LexInfo.3 Apache::RegistryLexInfo.3

.include <bsd.port.post.mk>
