# Ports collection makefile for:	Slay
# Date created:				Sun Mar 12 02:26:49 GMT 2000
# Whom:					scorpio@drkshdw.org
#
# $FreeBSD$
#

PORTNAME=	Slay
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/admin/idle
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	scorpio@drkshdw.org
COMMENT=	Kills a login shell and process(es) of a user

NO_BUILD=	"binary distribution"

do-install:
	${INSTALL_SCRIPT}	${WRKSRC}/slay ${PREFIX}/bin

.include <bsd.port.mk>
