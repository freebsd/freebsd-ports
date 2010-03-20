# ex:ts=8
# Ports collection makefile for:	gaffitter
# Date created:			13 Mar 2010
# Whom:				corky1951@comcast.net
#
# $FreeBSD$
#

PORTNAME=	gaffitter
PORTVERSION=	0.6.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	corky1951@comcast.net
COMMENT=	A bin packing utility that uses a genetic algorithm

USE_BZIP2=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1
.endif

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
