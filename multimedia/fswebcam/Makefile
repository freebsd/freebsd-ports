PORTNAME=	fswebcam
PORTVERSION=	20200725
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Small and simple webcam software for *nix
WWW=		https://www.sanslogic.co.uk/fswebcam/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libgd.so:graphics/gd \
		libv4l2.so:multimedia/libv4l

USES=		localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	fsphil
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/fswebcam \
		share/man/man1/fswebcam.1.gz

.include <bsd.port.mk>
