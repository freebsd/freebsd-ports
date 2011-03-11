# New ports collection makefile for:	xenophilia
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xenophilia
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A theme module to make GTK+ look nicer

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/Xenophilia-${PORTVERSION}

USE_GNOME=	gtk12
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
