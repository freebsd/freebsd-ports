# New ports collection makefile for:	portconf
# Date created:			7 Jun 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the files directory.
#

PORTNAME=	portconf
PORTVERSION=	1.5
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A universal tool to set specific port knobs

NO_BUILD=	yes
SUB_FILES=	pkg-message ${PORTNAME}.sh

PLIST_FILES=	libexec/${PORTNAME}

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/libexec/${PORTNAME}
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
