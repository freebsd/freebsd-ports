# New ports collection makefile for:	Perlbal::Plugin::PSGI
# Date created:		23 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perlbal-Plugin-PSGI
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for PSGI web server on Perlbal

RUN_DEPENDS=	\
	p5-Perlbal>0:${PORTSDIR}/www/perlbal \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Perlbal::Plugin::PSGI.3

.include <bsd.port.mk>
