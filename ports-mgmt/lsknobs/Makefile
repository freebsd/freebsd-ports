# New ports collection makefile for:	lsknobs
# Date created:							5 Sep 2007
# Whom:									Gabriel Linder <linder.gabriel@gmail.com>
#
# $FreeBSD$
#
# This port is self contained in the files directory.
#

PORTNAME=	lsknobs
PORTVERSION=	1.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	linder.gabriel@gmail.com
COMMENT=	Simple script to help configure ports knobs and options

RUN_DEPENDS=	${LOCALBASE}/libexec/portconf:${PORTSDIR}/ports-mgmt/portconf

NO_BUILD=	yes
SUB_FILES=	pkg-message ${PORTNAME}.sh

PLIST_FILES=	sbin/${PORTNAME}

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/sbin/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
