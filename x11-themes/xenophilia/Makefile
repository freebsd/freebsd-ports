# New ports collection makefile for:	xenophilia
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xenophilia
PORTVERSION=	0.8
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A theme module to make GTK+ look nicer

WRKSRC=		${WRKDIR}/Xenophilia-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CFLAGS+=	-DG_DISABLE_CHECKS -fPIC

ENGINES_DIR=	${PREFIX}/lib/gtk/themes/engines
THEMES_DIR=	${PREFIX}/share/themes

post-patch:
	@${REINPLACE_CMD} -e 's| make -C| $$(MAKE) -C|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\.@VERSION@||g ; \
		 s|\.@MAJOR@||g' ${WRKSRC}/gtk-src/Makefile.in

do-install:
	${INSTALL_DATA} ${WRKSRC}/gtk-src/libxeno.so ${ENGINES_DIR}
	cd ${WRKSRC}/themes && ${FIND} "Xeno Buffed" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${THEMES_DIR} 
	cd ${WRKSRC}/themes && ${FIND} "Xeno Gradient" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${THEMES_DIR} 
	cd ${WRKSRC}/themes && ${FIND} "Xeno Helix" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${THEMES_DIR} 
	cd ${WRKSRC}/themes && ${FIND} "Xeno Perkele" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${THEMES_DIR} 
	cd ${WRKSRC}/themes && ${FIND} "Xeno Thin" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${THEMES_DIR} 
	cd ${WRKSRC}/themes && ${FIND} "Xenophilia" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${THEMES_DIR} 

.include <bsd.port.mk>
