# New ports collection makefile for:	replaceit
# Date created:				Fri Aug 17 20:15:02 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	replaceit
PORTVERSION=	1.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://pldaniels.com/replaceit/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A light replacement to the combination of sed/awk/grep/head/tail

PLIST_FILES=	bin/replaceit

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/replaceit ${PREFIX}/bin

.include <bsd.port.mk>
