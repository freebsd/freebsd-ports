# New ports collection makefile for:	p5-FCGI
# Date created:		2011-08-20
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FCGI
PORTVERSION=	0.73
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast CGI module

OPTIONS=	PURE_PERL "Build pure Perl version (experimental)" off

PERL_CONFIGURE=	yes

MAN3=		FCGI.3

.include <bsd.port.options.mk>

.if defined(WITH_PURE_PERL)
CONFIGURE_ARGS=	--pure-perl
PLIST_SUB=	PURE_PERL="@comment "
.else
PLIST_SUB=	PURE_PERL=""
.endif

regression-test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
