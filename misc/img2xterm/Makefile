PORTNAME=	img2xterm
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Display images on 256 color xterms

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick6

USE_GITHUB=	yes
GH_ACCOUNT=	kfei
USES=		gmake ncurses
PLIST_FILES=	bin/img2xterm

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/img2xterm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
