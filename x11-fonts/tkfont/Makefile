# New ports collection makefile for:	tkfont-1.1
# Version required:	1.1
# Date created:		11 May 1998
# Whom:			Brett Taylor
#
# $Id: Makefile,v 1.2 1998/08/07 22:43:09 asami Exp $
#

DISTNAME=	tkfont-1.1
CATEGORIES=     x11-fonts tk80
MASTER_SITES=	http://cdrom.com/pub/linux/tsx-11/sources/usr.bin.X11/

MAINTAINER=     brett@peloton.physics.montana.edu

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

NO_BUILD=	yes

post-patch:
	${SED} -e "s,#!/usr/X11/bin/wish,#!$(LOCALBASE)/bin/wish8.0," < ${WRKSRC}/tkfont > ${WRKSRC}/tkfont.new
	${MV} ${WRKSRC}/tkfont.new ${WRKSRC}/tkfont

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkfont ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/tkfont
	@${INSTALL_SCRIPT} ${WRKSRC}/GetFontDirs ${PREFIX}/lib/tkfont
	@for file in COPYING Bugs.txt FileMenu.txt FindFont FontDirs.txt FontTypes.txt HelpText.txt README WhatsNew.txt; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/tkfont; \
	done
.include <bsd.port.mk>
