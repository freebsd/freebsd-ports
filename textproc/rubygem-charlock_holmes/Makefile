PORTNAME=	charlock_holmes
DISTVERSION=	0.7.7
PORTREVISION=	7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Gems for character encoding detection
WWW=		https://github.com/brianmario/charlock_holmes

LICENSE=	MIT

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		gem

CONFIGURE_ARGS=	--with-icu-include=${LOCALBASE}/include

.include <bsd.port.mk>
