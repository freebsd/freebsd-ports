# New ports collection makefile for:	p5-Geo-Weather
# Date created:				2 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	Geo-Weather
PORTVERSION=	1.41
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		ftp://ftp.innercite.com/pub/perl/
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl module to retrieve weather information from weather.com

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=	Geo::Weather.3

.include <bsd.port.mk>
