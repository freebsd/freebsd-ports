# New ports collection makefile for:	cpulimit
# Date created:				April 1, 2011
# Whom:					Jesse
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
.endif

.include <bsd.port.mk>
