# New ports collection makefile for:	Authen-Simple-LDAP
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-LDAP
PORTVERSION=	0.2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Simple LDAP authentication

BUILD_DEPENDS=	${SITE_PERL}/Authen/Simple.pm:${PORTSDIR}/security/p5-Authen-Simple \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Authen::Simple::LDAP.3 Authen::Simple::ActiveDirectory.3

PERL_MODBUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
