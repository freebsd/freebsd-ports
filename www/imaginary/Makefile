PORTNAME=	imaginary
PORTVERSION=	20251108
PORTREVISION=	1
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
GH_TAGNAME=	6a274b488759a896aff02f52afee6e50b5e3a3ee
GH_TUPLE=	\
		h2non:bimg:v1.1.7:h2non_bimg/vendor/github.com/h2non/bimg \
		h2non:filetype:v1.1.0:h2non_filetype/vendor/github.com/h2non/filetype \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		rs:cors:7af7a1e09ba3:rs_cors/vendor/github.com/rs/cors \
		throttled:throttled:v2.15.0:throttled_throttled/vendor/github.com/throttled/throttled/v2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
