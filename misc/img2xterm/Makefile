PORTNAME=	img2xterm
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display images on 256 color xterms

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	kfei
USES=		gmake magick:6 ncurses
PLIST_FILES=	bin/img2xterm

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/img2xterm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
