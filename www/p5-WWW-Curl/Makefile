# Created by: Chris Larsen <darth@vader.dk>
# $FreeBSD$

PORTNAME=	WWW-Curl
PORTVERSION=	4.15
PORTREVISION=	1
CATEGORIES=	www ftp perl5
MASTER_SITES=	CPAN \
		http://curl.haxx.se/libcurl/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl extension interface for libcurl

LICENSE=	MIT

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_PERL5=	configure
USES=		perl5

MAN3=		WWW::Curl.3

.include <bsd.port.mk>
