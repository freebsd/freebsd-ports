# New ports collection makefile for:	mkcatalog
# Date created:		26 Oct 2000
# Whom:			shige
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	mkcatalog
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	shige@FreeBSD.org
COMMENT=	A maintainance utility for sgml catalog files

NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes
PLIST_FILES=	sbin/mkcatalog
SCRIPTS_ENV=	CONFIGURE_TARGETS=${CONFIGURE_TARGETS}

SRC=			${.CURDIR}/src
CONFIGURE_TARGETS=	mkcatalog

do-fetch:
	@${DO_NADA}

pre-configure:
	@for i in ${CONFIGURE_TARGETS} ; do \
	    ${CP} ${SRC}/$${i}.in ${WRKDIR} ; \
	done

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/mkcatalog ${PREFIX}/sbin/mkcatalog

.include <bsd.port.mk>
