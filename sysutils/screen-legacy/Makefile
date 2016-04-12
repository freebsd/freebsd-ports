# Created by: Andrey Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	screen
PORTVERSION=	4.0.3
PORTREVISION=	14
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
PKGNAMESUFFIX=	-legacy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Multi-screen window manager

OPTIONS_DEFINE=	CJK INFO MAN NETHACK XTERM_256 HOSTINLOCKED SHOWENC
OPTIONS_DEFAULT=	INFO MAN NETHACK XTERM_256
CJK_DESC=		Treat CJK ambiguous characters as full width
INFO_DESC=		Build and install info documentation
MAN_DESC=		Build and install man pages
NETHACK_DESC=		Enable nethack-style messages
XTERM_256_DESC=		Enable support for 256 colour xterm
HOSTINLOCKED_DESC=	Print user@host in locked message
SHOWENC_DESC=		Show encoding on the status line

OPTIONS_SUB=

USES=		cpe
CPE_VENDOR=	gnu

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
.if ${PORT_OPTIONS:MMAN}
MAKE_ARGS+=	-DWITH_MAN
.endif
.if ${PORT_OPTIONS:MINFO}
.if !exists(/usr/bin/install-info)
RUN_DEPENDS+=	install-info:print/texinfo
.endif
INFO=		screen
MAKE_ARGS+=	-DWITH_INFO
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

# treat CJK ambiguous characters as full width via option "cjkwidth"
.if ${PORT_OPTIONS:MCJK}
EXTRA_PATCHES+=	${FILESDIR}/opt-cjkwidth
.endif

.if ${PORT_OPTIONS:MHOSTINLOCKED}
EXTRA_PATCHES+= ${FILESDIR}/opt-hostinlocked
.endif

# show encoding on the status line via option "showenc"
.if ${PORT_OPTIONS:MSHOWENC}
EXTRA_PATCHES+=	${FILESDIR}/opt-showencoding
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/screen.info*
	@${REINPLACE_CMD} -e 's|/dev/ptmx|/nonexistent|' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc \
		${STAGEDIR}${EXAMPLESDIR}/screenrc

.include <bsd.port.mk>
