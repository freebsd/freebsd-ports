# New ports collection makefile for:	tkfont-1.1
# Date created:		11 May 1998
# Whom:			Brett Taylor
#
# $FreeBSD$
#

PORTNAME=	tkfont
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11-fonts tcl84 tk84
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tk based replacement for xfontsel

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes

post-patch:
	${SED} -e "s,/usr/local,${LOCALBASE}," \
		-e "s,#!/usr/X11/bin/wish,#!$(LOCALBASE)/bin/wish8.4," \
		 < ${WRKSRC}/tkfont > ${WRKSRC}/tkfont.new
	${MV} ${WRKSRC}/tkfont.new ${WRKSRC}/tkfont

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkfont ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/tkfont
	@for file in COPYING Bugs.txt FileMenu.txt FindFont FontDirs.txt FontTypes.txt HelpText.txt README WhatsNew.txt; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/tkfont; \
	done

.include <bsd.port.mk>
