# Created by: ports@c0decafe.net <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	ondir
PORTVERSION=	0.2.3
CATEGORIES=	misc
MASTER_SITES=	http://swapoff.org/files/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically executes scripts as you traverse directories

ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	PREFIX=${PREFIX} CONF=${PREFIX}/etc/ondirrc
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
