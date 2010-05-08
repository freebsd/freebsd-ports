# New ports collection makefile for:	p5-WWW-iTunesConnect
# Date created:				29 August 2009
# Whom:					Brandon Fosdick <bfoz@bfoz.net>
#
# $FreeBSD$
#

PORTNAME=	WWW-iTunesConnect
PORTVERSION=	1.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PKGNAME}

MAINTAINER=	bfoz@bfoz.net
COMMENT=	Client interface for Apple's iTunes Connect service

BUILD_DEPENDS=	p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-IO-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-IO-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		WWW::iTunesConnect.3

PLIST_FILES=	%%SITE_PERL%%/WWW/iTunesConnect.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/iTunesConnect/.packlist
PLIST_DIRS=	%%SITE_PERL%%/WWW \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/iTunesConnect \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW

.include <bsd.port.mk>
