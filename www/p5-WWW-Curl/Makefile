# New ports collection makefile for:	p5-WWW-Curl
# Date created:				24 July 2003
# Whom:					Chris Larsen <darth@vader.dk>
#
# $FreeBSD$
#

PORTNAME=	WWW-Curl
PORTVERSION=	2.0
CATEGORIES=	www ftp perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://curl.haxx.se/libcurl/perl/
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Perl binding interface for curl

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl:install

PERL_CONFIGURE=	yes

MAN3=		WWW::Curl.3 \
		WWW::Curl::easy.3 \
		Curl::easy.3

.include <bsd.port.mk>
