# Created by: Michael Haro <mharo@area51.fremont.ca.us>
# $FreeBSD$

PORTNAME=	naim
PORTVERSION=	0.11.8.3.2
CATEGORIES=	net-im irc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	j@scre.ws
COMMENT=	Console ncurses-based AIM, ICQ, IRC, and Lily client

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		ncurses tar:bzip2

PORTDOCS=	FAQ README commands.txt keyboard.txt

OPTIONS_DEFINE=	DETACH DOCS
DETACH_DESC=	Enable 'detach' feature (requires misc/screen)

.include <bsd.port.options.mk>

# Fix parallel (-jX) builds: events.c #include's generated "conio_cmds.h"
post-patch:
	@${ECHO_CMD} 'events.o: conio_cmds.h' >> ${WRKSRC}/src/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--with-pkgdocdir=${DOCSDIR}
.else
CONFIGURE_ARGS+=	--without-pkgdocdir
.endif

.if ${PORT_OPTIONS:MDETACH}
RUN_DEPENDS=	screen:sysutils/screen
CONFIGURE_ARGS+=	--enable-detach
.endif

.include <bsd.port.mk>
