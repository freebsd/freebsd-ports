PORTNAME=	imaginary
PORTVERSION=	2.5.1
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	HTTP microservice for high-level image processing
WWW=		https://gitlab.com/ideaplexus/imaginary

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext-runtime gnome go:modules pkgconfig
USE_RC_SUBR=	${PORTNAME}
USE_GNOME=	glib20

LIB_DEPENDS=	libvips.so:graphics/vips

USE_GITLAB=	yes
GL_ACCOUNT=	ideaplexus

GO_MODULE=	gitlab.com/ideaplexus/imaginary
GO_MOD_DIST=	gitlab

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
