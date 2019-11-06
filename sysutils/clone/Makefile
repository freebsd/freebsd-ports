# $FreeBSD$

PORTNAME=	clone
PORTVERSION=	1.0.7
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://cyclaero.com/public/clone/

MAINTAINER=	cyclaero@gmail.com
COMMENT=	File tree cloning tool

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE

USES=		compiler:c11

PLIST_FILES=	bin/clone \
		man/man1/clone.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/clone

.include <bsd.port.mk>
