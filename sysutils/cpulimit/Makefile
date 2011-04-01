# New ports collection makefile for:	cpulimit
# Date created:				30 Mar 2011
# Whom:					Jesse Smith <jessefrgsmith@yahoo.ca>
#
# $FreeBSD$
#

PORTNAME=	cpulimit
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A program to limit the CPU usage of a process

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
