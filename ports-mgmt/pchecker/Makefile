# New ports collection makefile for:	pchecker
# Date created:		2012-02-23
# Whom:			Alex Kozlov <spam@rm-rf.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	pchecker
PORTVERSION=	1.9
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	ak-various-projects

MAINTAINER=	ak@FreeBSD.org
COMMENT=	A tool that checks the ports tree for various errors

LICENSE=	BSD

USE_XZ=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
