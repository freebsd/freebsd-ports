# New ports collection makefile for:	filerunner
# Date created:		3 August 1996
# Whom:			lukin
#
# $FreeBSD$
#

PORTNAME=	filerunner
PORTVERSION=	11.12.25.15
CATEGORIES=	x11-fm tk
MASTER_SITES=	SF/${PORTNAME}/Release-${PORTVERSION}
DISTNAME=	fr-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filemanager with FTP capabilities. Uses Tcl/Tk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USE_TK_WRAPPER=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/FileRunner
.for file in COPYING FAQ HISTORY README fr frftp tclIndex *.tcl *.txt *.xpm
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/FileRunner
.endfor
	@${MKDIR} ${PREFIX}/lib/FileRunner/bitmaps
.for file in *.bit
	${INSTALL_DATA} ${WRKSRC}/bitmaps/${file} ${PREFIX}/lib/FileRunner/bitmaps
.endfor
.for file in fr frftp frcolor.tcl
	@${CHMOD} ${BINMODE} ${PREFIX}/lib/FileRunner/${file}
.endfor
	@${LN} -sf ${PREFIX}/lib/FileRunner/fr ${PREFIX}/bin/fr

.include <bsd.port.mk>
