# New ports collection makefile for:	Apache-DB
# Date created:	   11 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DB
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Debugging and profiling tools for mod_perl

PERL_CONFIGURE=	yes
USE_APACHE=	yes

MAN3=		Apache::DB.3 Apache::DProf.3 Apache::perl5db.3 \
		Apache::SmallProf.3

.include <bsd.port.pre.mk>

.if defined(WITH_MODPERL2)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif

.include <bsd.port.post.mk>
