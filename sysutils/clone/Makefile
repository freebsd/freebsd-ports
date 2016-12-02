# $FreeBSD$

PORTNAME=	clone
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://googledrive.com/host/0BzyUSAiURzitVGlOeXFsTW9XOVk/

MAINTAINER=	cyclaero@gmail.com
COMMENT=	File tree cloning tool

LICENSE=	BSD2CLAUSE

USES=		compiler:c11

PLIST_FILES=	bin/clone \
		man/man1/clone.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/clone

.include <bsd.port.mk>
