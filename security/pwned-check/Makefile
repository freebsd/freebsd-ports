# Created by: Charlie Root <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwned-check
PORTVERSION=	2.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	se@FreeBSD.org
COMMENT=	Check whether password is known to have been exposed in a data breach

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/src

SRC=		${.CURDIR}/src

SUB_FILES=	${PORTNAME}.sh ${PORTNAME}.1 pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>
