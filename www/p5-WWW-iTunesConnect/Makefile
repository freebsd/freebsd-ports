# New ports collection makefile for:	p5-WWW-iTunesConnect
# Date created:				29 August 2009
# Whom:					Brandon Fosdick <bfoz@bfoz.net>
#
# $FreeBSD$
#

PORTNAME=	WWW-iTunesConnect
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	bfoz@bfoz.net
COMMENT=	Client interface for Apple's iTunes Connect service

RUN_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		WWW::iTunesConnect.3

PLIST_FILES=	%%SITE_PERL%%/WWW/iTunesConnect.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/iTunesConnect/.packlist
PLIST_DIRS=	%%SITE_PERL%%/WWW \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/iTunesConnect \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
