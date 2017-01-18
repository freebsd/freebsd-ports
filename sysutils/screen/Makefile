# Created by: Andrey Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	screen
PORTVERSION=	4.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.gnu.org/gnu/screen/ \
		ftp://ftp.gnu.org/gnu/screen/ \
		ftp://gnu.mirror.iweb.com/screen/ \
		http://gnu.mirror.iweb.com/screen/ \
		http://mirror.sdunix.com/gnu/ \
		ftp://mirrors.kernel.org/gnu/screen/ \
		http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/ \
		GNU

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Multi-screen window manager

LICENSE=	GPLv3

OPTIONS_DEFINE=		INFO MAN NETHACK XTERM_256 SHOWENC SYSTEM_SCREENRC
OPTIONS_DEFAULT=	INFO MAN NETHACK XTERM_256 SOCKETS SYSTEM_SCREENRC
OPTIONS_SINGLE=		IPC
OPTIONS_SINGLE_IPC=	SOCKETS NAMED_PIPES
INFO_DESC=		Build and install info documentation
MAN_DESC=		Build and install man pages
NETHACK_DESC=		Enable nethack-style messages
XTERM_256_DESC=		Enable support for 256 colour xterm
SHOWENC_DESC=		Show encoding on the status line
SOCKETS_DESC=		Use new (4.2.1+) sockets for IPC (default)
NAMED_PIPES_DESC=	Use legacy (4.0.3) named pipes for IPC (override)
SYSTEM_SCREENRC_DESC=	Install system screenrc with helpful status line

OPTIONS_SUB=

USES=		gmake cpe ncurses

CPE_VENDOR=	gnu

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
.if ${PORT_OPTIONS:MMAN}
MAKE_ARGS+=	WITH_MAN=1
PLIST_SUB+=	MAN=""
.else
PLIST_SUB+=	MAN="@comment"
.endif
.if ${PORT_OPTIONS:MINFO}
INFO=		screen
MAKE_ARGS+=	WITH_INFO=1
.endif

# Enables support for 256 colour xterm.  Note that you may need to
# set up a custom termcap entry or .screenrc which modifies termcap
# to contain the following: Co#256:AB=\E[48;5;%dm:AF=\E[38;5;%dm
#
.if ${PORT_OPTIONS:MXTERM_256}
CFLAGS+=	-DCOLORS256
.endif

.if ! ${PORT_OPTIONS:MNETHACK}
CFLAGS+=	-DNONETHACK
.endif

# show encoding on the status line via option "showenc"
.if ${PORT_OPTIONS:MSHOWENC}
EXTRA_PATCHES+=	${FILESDIR}/opt-showencoding
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/screen.info*
	@${REINPLACE_CMD} -e 's|/dev/ptmx|/nonexistent|' ${WRKSRC}/configure

# Bug 191029:	Users can choose whether to use sockets or named pipes.
# 		Choose sockets if you don't know what the difference is.
# 		Choose named pipes if your environment is heterogeneous,
#		using both screen 4.0.3 and 4.2.1.
# Bug 191017
post-configure-NAMED_PIPES-on:
	@${ECHO_CMD} '#define NAMEDPIPE 1' >> ${WRKSRC}/config.h
	@${ECHO_CMD} User selected named pipes override set.

ETCDIR?=	${PREFIX}/etc

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc \
		${STAGEDIR}${EXAMPLESDIR}/screenrc.sample-1
	${INSTALL_DATA} ${FILESDIR}/screenrc.sample \
		${STAGEDIR}${EXAMPLESDIR}/screenrc.sample-2
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.if ${PORT_OPTIONS:MSYSTEM_SCREENRC}
	${INSTALL_DATA} ${FILESDIR}/screenrc.sample \
		${STAGEDIR}${ETCDIR}/screenrc.sample
.else
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc \
		${STAGEDIR}${ETCDIR}/screenrc.sample
.endif

.include <bsd.port.mk>
