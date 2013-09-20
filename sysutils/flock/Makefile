# Created by: Andrey Zonov <andrey@zonov.org>
# $FreeBSD$

PORTNAME=	flock
PORTVERSION=	2.19
CATEGORIES=	sysutils
MASTER_SITES=	http://www.zonov.org/${PORTNAME}/

MAINTAINER=	zont@FreeBSD.org
COMMENT=	Manage locks from shell scripts

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
