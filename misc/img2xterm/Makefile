PORTNAME=	img2xterm
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	misc

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Display images on 256 color xterms
WWW=		https://github.com/kfei/img2xterm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake magick ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	kfei
PLIST_FILES=	bin/img2xterm

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/img2xterm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
