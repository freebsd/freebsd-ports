# New ports collection makefile for:	rcorder
# Date created:		Sat Apr 27 17:49:09 CET 2002
# Whom:			Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	rclean
PORTVERSION=	1.14
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lapo.it/rclean/

MAINTAINER=	lapo@lapo.it
COMMENT=	Command-line rc.conf ordering and cleaning tool

PLIST_FILES=	bin/rclean
USE_BZIP2=	yes

do-build:
	@(cd ${WRKSRC}; ${CC} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
