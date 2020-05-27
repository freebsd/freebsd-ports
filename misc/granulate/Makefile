# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	granulate
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	https://github.com/jharris3299/distfiles/raw/master/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Program for splitting files in place

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/granulate

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g" \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
