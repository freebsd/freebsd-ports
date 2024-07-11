PORTNAME=	charlock_holmes
PORTVERSION=	0.7.9
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide binary and text detection as well as text transcoding using libicu
WWW=		https://github.com/brianmario/charlock_holmes

LICENSE=	MIT

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		gem

CONFIGURE_ARGS=	--with-icu-include=${LOCALBASE}/include

.include <bsd.port.mk>
