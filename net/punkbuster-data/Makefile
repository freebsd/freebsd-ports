# New ports collection makefile for:	punkbuster anti cheat server data file
# Date created:		29 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	punkbuster
PORTVERSION=	0.1157.0
CATEGORIES=	net linux
MASTER_SITES=	http://www.evenbalance.com/downloads/
PKGNAMESUFFIX=	-data
EXTRACT_SUFX=
DISTFILES=	cvar.cfg pbclhl.dat pbclhl_
DIST_SUBDIR=	punkbuster/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org

NO_PACKAGE=	the software terms do not allow non-standard\
		${PORTNAME} distributions

NO_BUILD=	yes
PLIST_SUB=	PUNKBUSTER_DIR="${PUNKBUSTER_DIR:S/^\///}/" \
		PUNKBUSTER_DATA="${PUNKBUSTER_DATA}"

INSTALL_DIR=    ${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

# pkg data files
DESCR=		${PUNKBUSTER_PORT}/pkg-descr
PKGMESSAGE=		${PUNKBUSTER_PORT}/pkg-message

USE_LINUX_PREFIX=	yes
PUNKBUSTER_PORT=   ${.CURDIR}/../punkbuster
# the later is not working, hummm. Help?
#PUNKBUSTER_DIR!=	cd ${PUNKBUSTER_PORT} && ${MAKE} -V PUNKBUSTER_DIR
PUNKBUSTER_DIR=	/usr/games/punkbuster
PUNKBUSTER_DATA=	${PKGNAME}

do-install:
	@${INSTALL_DIR} ${PREFIX}${PUNKBUSTER_DIR}
	@${TOUCH} ${PREFIX}${PUNKBUSTER_DIR}/${PKGNAME}
.for file in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${file} \
		${PREFIX}${PUNKBUSTER_DIR}
.endfor
	@(cd ${PUNKBUSTER_PORT} && ${MAKE} pkgmessage-output)

.include <bsd.port.mk>
