# $FreeBSD$

PORTNAME=	clone
PORTVERSION=	1.0.5
CATEGORIES=	sysutils
MASTER_SITES=	https://googledrive.com/host/0BzyUSAiURzitVGlOeXFsTW9XOVk/

MAINTAINER=	cyclaero@gmail.com
COMMENT=	File tree cloning tool

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/clone \
		man/man1/clone.1.gz

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/clone

.include <bsd.port.mk>
