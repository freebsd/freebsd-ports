PORTNAME=	screen
DISTVERSION=	5.0.1
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	GNU \
	        ftp://ftp.gnu.org/gnu/screen/ \
	        ftp://gnu.mirror.iweb.com/screen/ \
	        http://gnu.mirror.iweb.com/screen/ \
	        http://mirror.sdunix.com/gnu/ \
	        ftp://mirrors.kernel.org/gnu/screen/ \
	        http://cschubert.com/distfiles/ \
	        LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Multi-screen window manager
WWW=		https://www.gnu.org/software/screen/

CONFLICTS+=	screen-devel

LICENSE=	GPLv3

OPTIONS_DEFINE=		INFO SYSTEM_SCREENRC MULTIUSER \
			NOSOCKETDIR
OPTIONS_DEFAULT=	INFO SYSTEM_SCREENRC \
			NCURSES_DEFAULT MULTIUSER
OPTIONS_SINGLE=		NCURSES
OPTIONS_SINGLE_NCURSES=	NCURSES_DEFAULT NCURSES_BASE NCURSES_PORT
SYSTEM_SCREENRC_DESC=	Install system screenrc with helpful status line
MULTIUSER_DESC=		Install setuid-root screen to support multiuser
MULTIUSER_PLIST_SUB=	MULTISUID="@(,,4555) "
MULTIUSER_PLIST_SUB_OFF=MULTISUID="@(,,0555) "
NCURSES_DEFAULT_DESC=	Depend on ncurses (ports if installed, otherwise base)
NCURSES_BASE_DESC=	Depend on ncurses in base
NCURSES_PORT_DESC=	Depend on devel/ncurses in ports
NOSOCKETDIR_DESC=	Use ~/.screen instead of socketdir

NCURSES_DEFAULT_USES=	ncurses
NCURSES_BASE_USES=	ncurses:base
NCURSES_PORT_USES=	ncurses:port

OPTIONS_SUB=

USES=		autoreconf:build gmake cpe
CONFIGURE_ARGS=	--with-system_screenrc=${ETCDIR}/screenrc
MAKE_ARGS+=	WITH_MAN=1

CPE_VENDOR=	gnu

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX= ${PREFIX}/share
CFLAGS+=	-I${NCURSESINC} -DSVR4 -DGETUTENT
LDFLAGS+=	-L${NCURSESLIB}

.if ${PORT_OPTIONS:MINFO}
INFO=		screen
MAKE_ARGS+=	WITH_INFO=1
USES+=		makeinfo
.endif

# Enables support for 256 colour xterm.  Note that you may need to
# set up a custom termcap entry or .screenrc which modifies termcap
# to contain the following: Co#256:AB=\E[48;5;%dm:AF=\E[38;5;%dm
#
.if ${PORT_OPTIONS:MNOSOCKETDIR}
CONFIGURE_ARGS+=	--disable-socket-dir
.endif

.if defined(SCREEN_SOCKET_DIR)
CONFIGURE_ARGS+=	--enable-socket-dir=${SCREEN_SOCKET_DIR}
.endif

# Bug 191029:	Users can choose whether to use sockets or named pipes.
#		Choose sockets if you don't know what the difference is.
#		Choose named pipes if your environment is heterogeneous,
#		using both screen 4.0.3 and 4.2.1.
# Bug 191017

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

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
