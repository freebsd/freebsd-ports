# ex:ts=8
# Ports collection makefile for:	ised
# Date created:		20 Mar 2010
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	ised
PORTVERSION=	2.3.0
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	A tool for generating number sequences and arithmetic evaluation

LICENSE=	GPLv3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GCC=	4.5+

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1
.endif

PLIST_FILES=		bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
