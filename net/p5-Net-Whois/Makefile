# New ports collection makefile for:	p5-Net-Whois
# Date created:				June 7th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Whois
PORTVERSION=	1.9
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A perl5 module to get information using the Whois protocol

RUN_DEPENDS=	${SITE_PERL}/Locale/Country.pm:${PORTSDIR}/misc/p5-Locale-Codes

PERL_CONFIGURE=	YES

MAN3=		Net::Whois.3

.include <bsd.port.mk>
