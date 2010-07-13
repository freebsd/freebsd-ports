# New ports collection makefile for:	p5-Net-Whois-Raw
# Date created:				March 25th 2002
# Whom:	      				Alex Kapranoff <kappa@freebsd.org.ua>
#
# $FreeBSD$
#

PORTNAME=	Net-Whois-Raw
PORTVERSION=	2.22
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Very simple Perl interface to query raw whois data

RUN_DEPENDS=	${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Whois::Raw.3
MAN1=		pwhois.1

.include <bsd.port.mk>
