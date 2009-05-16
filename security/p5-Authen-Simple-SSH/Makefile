# New ports collection makefile for:	Authen-Simple-SSH
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-SSH
PORTVERSION=	0.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Simple SSH authentication

BUILD_DEPENDS=	${SITE_PERL}/Authen/Simple.pm:${PORTSDIR}/security/p5-Authen-Simple \
		${SITE_PERL}/Net/SSH/Perl.pm:${PORTSDIR}/net/p5-Net-SSH-Perl
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=	Authen::Simple::SSH.3

PERL_MODBUILD=	5.8.0+

.include <bsd.port.mk>
