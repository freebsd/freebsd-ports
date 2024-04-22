PORTNAME=	paperclip-av-transcoder
PORTVERSION=	0.6.4
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Audio/Video transcoder for Paperclip using FFMPEG/Avconv
WWW=		https://github.com/ruby-av/paperclip-av-transcoder/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Depends on deprecated port devel/rubygem-paperclip-rails5
EXPIRATION_DATE=2024-04-30

RUN_DEPENDS=	rubygem-av>=0.9.0:multimedia/rubygem-av \
		rubygem-paperclip-rails5>=2.5.2:devel/rubygem-paperclip-rails5

NO_ARCH=	yes

USES=		gem

.include <bsd.port.mk>
