# New ports collection makefile for:  wanted-ports
# Date created:    7 June 2010
# Whom:            Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#
# port is self-contained in the files directory.

PORTNAME=	wanted-ports
PORTVERSION=	0.1
#PORTREVISION is set from ${CFGFILE}
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Just depend on a configurable, arbitrary set of other ports

LICENSE=	BSD

NO_BUILD=	yes
SUB_FILES=	${PORTNAME}   \
		${PORTNAME}.1
SUB_LIST=	PORTNAME=${PORTNAME} \
		PKGNAME=${PKGNAME}
PLIST_SUB=	PORTNAME=${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

MAN1=		${PORTNAME}.1

.if defined(WANTEDPORTSCFG)
CFGFILE=	${WANTEDPORTSCFG}
.else
CFGFILE?=	/var/db/${PORTNAME}.conf
.endif

.if exists(${CFGFILE})
.include "${CFGFILE}"
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
