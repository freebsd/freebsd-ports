# Created by: Brandon Fosdick <bfoz@bfoz.net>
# $FreeBSD$

PORTNAME=	WWW-iTunesConnect
PORTVERSION=	1.16
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	bfoz@bfoz.net
COMMENT=	Client interface for Apple's iTunes Connect service

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-HTML-Form>=0:${PORTSDIR}/www/p5-HTML-Form
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::iTunesConnect.3

PLIST_FILES=	%%SITE_PERL%%/WWW/iTunesConnect.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/iTunesConnect/.packlist
PLIST_DIRS=	%%SITE_PERL%%/WWW \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/iTunesConnect \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW

NO_STAGE=	yes
.include <bsd.port.mk>
