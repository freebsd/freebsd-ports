# Ports collection makefile for: gnugadu
# Date created:		23 dec 2001
# Whom: 		doc@lublin.t1.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	polish net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggadu
DISTNAME=	gg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GaduGadu client for X11/GTK

DEPRECIATED=	Not developed anymore, unmaintained, etc.
EXPIRE_DATE=	2006-07-15

USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

OPTIONS=	ESD "Esound support" on \
		GNOME "Gnome support" off \
		PANEL "Gnome applet support" off

.include <bsd.port.pre.mk>
.if !defined(WITHOUT_ESD)
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-esd
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gnomelibs
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_PANEL)
USE_GNOME+=	gnomepanel
CONFIGURE_ARGS+=	--enable-panel
.else
CONFIGURE_ARGS+=	--disable-panel
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,GTK_ CFLAGS,GTK_CFLAGS,' \
		-e 's,CFLAGS =, CFLAGS += @GTK_CFLAGS@ ${PTHREAD_CFLAGS},' \
		-e 's,@GTK_LIBS@,@GTK_LIBS@ ${PTHREAD_LIBS},'\
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,-O2,,' -e 's,gtk-config,${GTK_CONFIG},' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gg

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
