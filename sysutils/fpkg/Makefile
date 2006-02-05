# New ports collection makefile for:	fpkg
# Date created:		28 January 2006
# Whom:			Yuki SHIMAZU  <y.shimazu@nifty.com>
#
# $FreeBSD$
#

PORTNAME=	fpkg
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.shimazu.org/fpkg/
EXTRACT_SUFX=

MAINTAINER=	y.shimazu@nifty.com
COMMENT=	Package Tool Wrapper for FreeBSD

USE_PERL5=	YES
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
PLIST_SUB=	INSTALL_BASE=${INSTALL_BASE}

INSTALL_BASE=	bin
INSTALL_DIR=	${PREFIX}/${INSTALL_BASE}

do-install:
	${MKDIR} ${INSTALL_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${INSTALL_DIR}/${PORTNAME}

.include <bsd.port.mk>
