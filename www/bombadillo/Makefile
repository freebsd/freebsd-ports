PORTNAME=	bombadillo
DISTVERSION=	2.4.0
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	https://tildegit.org/sloum/bombadillo/archive/
DISTNAME=	${DISTVERSION}

MAINTAINER=	beastieboy@beastieboy.net
COMMENT=	Non-web client for the terminal
WWW=		https://bombadillo.colorfield.space/

LICENSE=	GPLv3

USES= go:modules

WRKSRC=		${WRKDIR}/${PORTNAME}

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/bombadillo \
		share/man/man1/bombadillo.1.gz

post-stage:
	${INSTALL_MAN} ${WRKSRC}/bombadillo.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
