# New ports collection makefile for:		etcmerge
# Date created:					05 July 2003
# Whom:						eivind
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	etcmerge
PORTVERSION=	0.4
PORTREVISION=	0
CATEGORIES=	sysutils textproc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	eivind@FreeBSD.org
COMMENT=	"Automatic 3-way merge of /etc updates"

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_MAN=		yes

SRC=		${.CURDIR}/src

MAN8=		${PORTNAME}.8
PLIST_FILES=	sbin/etcmerge

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${SRC}/${PORTNAME}.sh ${PREFIX}/sbin/${PORTNAME}
	@${INSTALL_MAN} ${SRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
