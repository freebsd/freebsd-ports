# New ports collection makefile for:	www/p5-URI-Title
# Date created:				20 June 2008
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-Title
PORTVERSION=	1.80
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	URI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Get the titles of things on the web in a sensible way

BUILD_DEPENDS=	p5-Module-Pluggable>=1.2:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-File-Type>=0.22:${PORTSDIR}/devel/p5-File-Type \
		p5-HTML-Parser>=3.45:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Image-Size>0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-MP3-Info>0:${PORTSDIR}/audio/p5-MP3-Info
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	URI::Title.3

.include <bsd.port.mk>
