# Created by: jhb
# $FreeBSD$

PORTNAME=	etcupdate
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Manage updates to /etc automatically

LICENSE=	BSD

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SRC=		${.CURDIR}/src

PLIST_FILES=	sbin/etcupdate man/man8/etcupdate.8.gz

do-install:
	${INSTALL_SCRIPT} ${SRC}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${SRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
