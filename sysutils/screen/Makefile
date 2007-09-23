# New ports collection makefile for:	screen
# Date created:         25 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	screen
PORTVERSION=	4.0.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	screen

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A multi-screen window manager

GNU_CONFIGURE=	yes
.if defined(NO_MAN)
MAKE_ARGS+=	-DNO_MAN
.else
MAN1=		screen.1
.endif
.if defined(NO_INFO)
MAKE_ARGS+=	-DNO_INFO
.else
.if !exists(/usr/bin/install-info)
RUN_DEPENDS+=	install-info:${PORTSDIR}/print/texinfo
.endif
INFO=		screen
.endif

NO_PACKAGE=	Tends to loop using 100% CPU when used from package - perhaps it hard-codes information about the build host

.include <bsd.port.pre.mk>

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

.if defined(WITHOUT_NETHACK)
CFLAGS+=	-DNONETHACK
.endif

# treat CJK ambiguous characters as full width via option "cjkwidth"
.if defined(WITH_CJK)
EXTRA_PATCHES+=	${.CURDIR}/files/opt-cjkwidth
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/screen.info*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/etc/etcscreenrc ${EXAMPLESDIR}/screenrc
	@if [ ! -f ${PREFIX}/etc/screenrc ]; then \
		${CP} ${EXAMPLESDIR}/screenrc ${PREFIX}/etc/screenrc ; \
	fi

.include <bsd.port.post.mk>
