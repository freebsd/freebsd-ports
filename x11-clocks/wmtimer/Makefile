# New ports collection makefile for:	wmtimer
# Date created:			Thu Apr 26 16:46:38 EDT 2001
# Whom:				Patrick Li <pat@databits.net> et al
#
# $FreeBSD$
#

PORTNAME=	wmtimer
PORTVERSION=	2.2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://home.dwave.net/~jking/wmtimer/

MAINTAINER=	pat@databits.net

WRKSRC=		${WRKDIR}/${DISTNAME}/wmtimer
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GTK=	yes

.if !defined(BATCH)
HAS_CONFIGURE=	yes
IS_INTERACTIVE=	yes
.endif # !BATCH

pre-patch:
	@${PERL} -pi -n \
		-e "s!CFLAGS =! CFLAGS \+=!;" \
		-e "s!-I/usr/lib/glib/include!`${GTK_CONFIG} --cflags` `${GLIB_CONFIG} --cflags`!;" \
		-e "s!-lgtk -lgdk -rdynamic -lgmodule -lglib -ldl!`${GTK_CONFIG} --libs` `${GLIB_CONFIG} --libs`!;" \
		-e "s!/usr/X11R6/lib!${X11BASE}/lib!;" \
		-e "s!/usr/X11R6/include!${X11BASE}/include!;" \
		-e "s!/usr/lib!${LOCALBASE}/lib!;" \
		${WRKSRC}/Makefile
.if defined(IS_INTERACTIVE)
	@${PERL} -pi -ne "s!/bin/bash!${SH}!" ${WRKSRC}/configure
.endif # IS_INTERACTIVE

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtimer ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/wmtimer
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmtimer
.endif # !NOPORTDOCS

.include <bsd.port.mk>
