# New ports collection makefile for:	proggy_fonts
# Date Created:				30 July 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	proggy_fonts
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.proggyfonts.com/download/
DISTFILES=	ProggyClean.pcf.zip ProggySquare.pcf.zip	\
		ProggySmall.pcf.zip ProggyTiny.pcf.zip	\
		ProggyCleanSZ.pcf.zip ProggySquareSZ.pcf.zip	\
		ProggyTinySZ.pcf.zip ProggyCleanSZBP.pcf.zip	\
		ProggyCleanCP.pcf.zip

MAINTAINER=	llwang@infor.org
COMMENT=	The perfect monospaced bitmap programming fonts

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
XFONTDIR=	${PREFIX}/lib/X11/fonts/local

do-install:
	@${MKDIR} ${XFONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/*.pcf.gz ${XFONTDIR}
	@(cd ${XFONTDIR}; mkfontdir)

.include <bsd.port.mk>
