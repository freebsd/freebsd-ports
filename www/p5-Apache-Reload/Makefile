# New ports collection makefile for:	Apache::Reload
# Date created:		15 Jan 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-Reload
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Reload changed modules

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		Apache2::Reload.3 Apache::Reload.3

.include <bsd.port.pre.mk>

.if defined(WITH_MODPERL2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
MAKE_ENV+=	MOD_PERL=2
_APACHE=	Apache2
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
MAKE_ENV+=	MOD_PERL=1
_APACHE=	Apache
.endif

PLIST_DIRS=	%%SITE_PERL%%/Apache2 \
	%%SITE_PERL%%/Apache \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/${_APACHE}/Reload

PLIST_FILES=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/${_APACHE}/Reload/.packlist \
	%%SITE_PERL%%/Apache2/Reload.pm \
	%%SITE_PERL%%/Apache/Reload.pm

.include <bsd.port.post.mk>
