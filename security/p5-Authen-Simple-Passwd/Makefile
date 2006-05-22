# New ports collection makefile for:	Authen-Simple-Passwd
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-Passwd
PORTVERSION=	0.6
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Simple Passwd authentication

BUILD_DEPENDS=	${SITE_PERL}/Authen/Simple.pm:${PORTSDIR}/security/p5-Authen-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Authen::Simple::Passwd.3

PERL_MODBUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
