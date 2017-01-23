# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nms
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	misc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Recreate decrypting text effect from the Sneakers movie

LICENSE=	GPLv3

USES=		gmake ncurses
MAKE_ARGS+=	NCURSES_H=${NCURSESINC}/ncurses.h

USE_GITHUB=	yes
GH_ACCOUNT=	bartobri
GH_PROJECT=	no-more-secrets
PLIST_FILES=	bin/${PORTNAME} \
		bin/sneakers

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sneakers ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
