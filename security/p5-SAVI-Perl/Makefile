# New ports collection makefile for:	p5-SAVI-Perl
# Date created:				April 8th 2004
# Whom:	      				Gary Hayers <Gary@Hayers.net>
#
# $FreeBSD$

PORTNAME=	SAVI-Perl
PORTVERSION=	0.30
CATEGORIES=	security perl5
MASTER_SITES=	http://www.csupomona.edu/~henson/www/projects/SAVI-Perl/dist/
MASTER_SITE_SUBDIR=	security
PKGNAMEPREFIX=	p5-

MAINTAINER=	Gary@Hayers.net
COMMENT=	Perl5 module interface to Sophos AntiVirus

MAN=		SAVI.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	Port requires perl 5.6 or newer. Upgrade your perl and try again.  \
	If your perl is up to date then you might haven't run 'use.perl ports' \
	yet.
.endif

.include <bsd.port.post.mk>
