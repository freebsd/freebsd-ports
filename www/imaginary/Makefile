PORTNAME=	imaginary
PORTVERSION=	20250114
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	HTTP microservice for high-level image processing
WWW=		https://github.com/h2non/imaginary

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext-runtime gnome go:modules pkgconfig
USE_RC_SUBR=	${PORTNAME}
USE_GNOME=	glib20

LIB_DEPENDS=	libvips.so:graphics/vips

USE_GITHUB=	yes
GH_ACCOUNT=	h2non
GH_TAGNAME=	1d4e251cfcd58ea66f8361f8721d7b8cc85002a3
GH_TUPLE=	\
		garyburd:redigo:v1.6.0:garyburd_redigo/vendor/github.com/garyburd/redigo \
		h2non:bimg:v1.1.7:h2non_bimg/vendor/github.com/h2non/bimg \
		h2non:filetype:v1.1.0:h2non_filetype/vendor/github.com/h2non/filetype \
		hashicorp:golang-lru:0a025b7e63ad:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		rs:cors:7af7a1e09ba3:rs_cors/vendor/github.com/rs/cors \
		throttled:throttled:v2.0.3:throttled_throttled/vendor/github.com/throttled/throttled/v2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
