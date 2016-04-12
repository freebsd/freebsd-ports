# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	URI-Title
PORTVERSION=	1.86
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Get the titles of things on the web in a sensible way

COMMON_DEPENDS=	p5-File-Type>=0.22:devel/p5-File-Type \
		p5-HTML-Parser>=3.45:www/p5-HTML-Parser \
		p5-Image-Size>0:graphics/p5-Image-Size \
		p5-MP3-Info>0:audio/p5-MP3-Info \
		p5-libwww>0:www/p5-libwww
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	title.pl
USE_PERL5=	configure

.include <bsd.port.mk>
