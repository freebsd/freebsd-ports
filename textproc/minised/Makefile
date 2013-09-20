# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minised
PORTVERSION=	1.14
CATEGORIES=	textproc
MASTER_SITES=	http://dl.exactcode.de/oss/minised/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Smaller, cheaper, faster sed implementation

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-O1||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
