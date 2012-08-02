# New ports collection makefile for:		cdiff
# Date created:					September 20th 2000
# Whom:						eivind
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	cdiff
PORTVERSION=	1.5
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Diff readability enhancer for color terminals

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes

SRC=		${.CURDIR}/src

MAN1=		cdiff.1
PLIST_FILES=	bin/cdiff

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${SRC}/cdiff.sh ${PREFIX}/bin/cdiff
	@${INSTALL_MAN} ${SRC}/cdiff.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
