# New ports collection makefile for:	pchecker
# Date created:		2012-02-23
# Whom:			Alex Kozlov <spam@rm-rf.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	pchecker
PORTVERSION=	1.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	A tool that checks the ports tree for various errors

LICENSE=	BSD

PROJECTHOST=	ak-various-projects

USE_XZ=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
