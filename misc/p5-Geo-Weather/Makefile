# New ports collection makefile for:	p5-Geo-Weather
# Date created:				2 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	Geo-Weather
PORTVERSION=	0.08
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		ftp://ftp.innercite.com/pub/perl/
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@databits.net

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Geo::Weather.3

.include <bsd.port.mk>
