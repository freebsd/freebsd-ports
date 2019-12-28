# $FreeBSD$

PORTNAME=	streamio-ffmpeg
PORTVERSION=	3.0.2
PORTREVISION=	3
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Wraps ffmpeg to read metadata and transcodes videos

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=1.8<2:devel/rubygem-multi_json \
		ffmpeg>=3.4.2,1:multimedia/ffmpeg

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
