# Created by: Devin Teske <dteske@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysrc
PORTVERSION=	5.2
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Utility to get or set rc.conf(5) values

LICENSE=	BSD

NO_BUILD=	yes

MAN8=		${PORTNAME}.8

PLIST_FILES=	sbin/${PORTNAME}                   \
		share/${PORTNAME}/common.subr      \
		share/${PORTNAME}/${PORTNAME}.subr \
		libexec/${PORTNAME}/include/messages.subr

PLIST_DIRS=	share/${PORTNAME}           \
		libexec/${PORTNAME}/include \
		libexec/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/common.subr ${PREFIX}/share/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.subr ${PREFIX}/share/${PORTNAME}/
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}/include
	${INSTALL_DATA} ${WRKSRC}/messages.subr ${PREFIX}/libexec/${PORTNAME}/include/
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8/

.include <bsd.port.mk>
