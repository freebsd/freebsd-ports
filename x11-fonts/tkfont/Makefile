# Created by: Brett Taylor
# $FreeBSD$

PORTNAME=	tkfont
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11-fonts tcl tk
MASTER_SITES=	LOCAL/petef

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk based replacement for xfontsel

USES+=		tk:run
RUN_DEPENDS+=	xlsfonts:x11-fonts/xlsfonts
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; s|#!/usr/X11/bin/wish|${WISH}|;' \
	    ${WRKSRC}/tkfont

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkfont ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tkfont
.for file in COPYING Bugs.txt FileMenu.txt FindFont FontDirs.txt FontTypes.txt HelpText.txt README WhatsNew.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/lib/tkfont
.endfor

.include <bsd.port.mk>
