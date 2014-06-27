# Created by: Jouke Witteveen <j.witteveen@gmail.com>
# $FreeBSD$

PORTNAME=	respond
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	j.witteveen@gmail.com
COMMENT=	A response automator for logged events

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MANEXT=${MANEXT}

.include <bsd.port.mk>
