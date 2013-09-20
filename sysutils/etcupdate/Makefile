# Created by: jhb
# $FreeBSD$

PORTNAME=	etcupdate
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Manage updates to /etc automatically

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SRC=		${.CURDIR}/src

MAN8=		${PORTNAME}.8
PLIST_FILES=	sbin/etcupdate

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${SRC}/${PORTNAME}.sh ${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${SRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
