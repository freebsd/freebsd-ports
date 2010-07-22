# New ports collection makefile for:	screen
# Date created:         25 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	screen
PORTVERSION=	4.0.3
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	screen

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A multi-screen window manager

OPTIONS=	CJK "Treat CJK ambiguous characters as full width" OFF \
		INFO "Build and install info documentation" ON \
		MAN "Build and install man pages" ON \
		NETHACK "Enable nethack-style messages" ON \
		XTERM_256 "Enable support for 256 colour xterm" OFF \
		HOSTINLOCKED "Print user@host in locked message" OFF \
		SHOWENC "Show encoding on the status line" OFF

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
.if defined(WITH_MAN)
MAN1=		screen.1
MAKE_ARGS+=	-DWITH_MAN
.endif
.if defined(WITH_INFO)
.if !exists(/usr/bin/install-info)
RUN_DEPENDS+=	install-info:${PORTSDIR}/print/texinfo
.endif
INFO=		screen
MAKE_ARGS+=	-DWITH_INFO
.endif

.if ${ARCH} == "alpha"
CFLAGS+=	-O0
.endif

# Enables support for 256 colour xterm.  Note that you may need to
# set up a custom termcap entry or .screenrc which modifies termcap
# to contain the following: Co#256:AB=\E[48;5;%dm:AF=\E[38;5;%dm
#
.if defined(WITH_XTERM_256)
CFLAGS+=	-DCOLORS256
.endif

.if !defined(WITH_NETHACK)
CFLAGS+=	-DNONETHACK
.endif

# treat CJK ambiguous characters as full width via option "cjkwidth"
.if defined(WITH_CJK)
EXTRA_PATCHES+=	${FILESDIR}/opt-cjkwidth
.endif

.if defined(WITH_HOSTINLOCKED)
EXTRA_PATCHES+= ${FILESDIR}/opt-hostinlocked
.endif

# show encoding on the status line via option "showenc"
.if defined(WITH_SHOWENC)
EXTRA_PATCHES+=	${FILESDIR}/opt-showencoding
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/screen.info*
	@${REINPLACE_CMD} -e 's|/dev/ptmx|/nonexistent|' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/etc/etcscreenrc ${EXAMPLESDIR}/screenrc
	@if [ ! -f ${PREFIX}/etc/screenrc ]; then \
		${CP} ${EXAMPLESDIR}/screenrc ${PREFIX}/etc/screenrc ; \
	fi

.include <bsd.port.post.mk>
