# New ports collection makefile for:	bubblemon-dockapp
# Date created:			Apr 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	bubblemon-dockapp
PORTVERSION=	1.46
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}

MAINTAINER=	gurkan@phys.ethz.ch
COMMENT=	X eye candy for displaying CPU and memory load in a dock

USE_GMAKE=	yes
USE_GNOME=	gtk12
MAKE_ARGS+=	PREFIX="${PREFIX}"

PORTDOCS=	README

post-patch:
	${REINPLACE_CMD} -e "s@CC = gcc@CC = ${CC}@g; \
		s@-O3 -ansi -Wall@${CFLAGS} -Wall@g; \
		s@PREFIX = /usr/local@PREFIX = ${PREFIX}@g; \
		s@gtk-config@${GTK_CONFIG}@g; s@-lgtk@-lgtk-1.2@g; \
		s@-c -g kmem -m 2755 -o root@-s -c -g kmem -m 2755 -o root@g" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|-lkvm||g' ${WRKSRC}/Makefile.FreeBSD

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/wak.wav ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/wakwak.sh ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Xdefaults.sample ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
