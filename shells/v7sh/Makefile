# New ports collection makefile for:   v7sh
# Date created:        4 June 2004
# Whom:                Cyrille.Lefevre@laposte.net
#
# $FreeBSD$
#

PORTNAME=	v7sh
PORTVERSION=	1.0
CATEGORIES=	shells
MASTER_SITES=	ftp://minnie.tuhs.org/UnixArchive/PDP-11/Trees/V7/usr/src/cmd/sh/:s \
		http://minnie.tuhs.org/UnixTree/V7/usr/src/cmd/sh/:s \
		ftp://minnie.tuhs.org/UnixArchive/PDP-11/Trees/V7/usr/man/man1/:m \
		http://minnie.tuhs.org/UnixTree/V7/usr/man/man1/:m
DISTFILES=	args.c:s blok.c:s brkincr.h:s builtin.c:s cmd.c:s \
		ctype.c:s ctype.h:s defs.h:s error.c:s expand.c:s \
		fault.c:s io.c:s mac.h:s macro.c:s main.c:s mode.h:s \
		msg.c:s name.c:s name.h:s print.c:s service.c:s \
		setbrk.c:s stak.c:s stak.h:s string.c:s sym.h:s \
		timeout.h:s word.c:s xec.c:s sh.1:m
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	Cyrille.Lefevre@laposte.net
COMMENT=	An implementation of the UNIX 7th Edition shell

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}

NO_WRKSUBDIR=	yes
MAN1=		${PORTNAME}.1

OPTIONS=	V7SH_SYSIII	"System III enhancements"	on \
		V7SH_RENO	"4.3BSD-Reno enhancements"	on \
		V7SH_ULTRIX	"Ultrix 3.1 enhancements"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_V7SH_SYSIII)
CFLAGS+=	-DSYSIII
.endif
.if !defined(WITHOUT_V7SH_RENO)
CFLAGS+=	-DRENO
.endif
.if !defined(WITHOUT_V7SH_ULTRIX)
CFLAGS+=	-DULTRIX
.endif

post-extract:
	@${MV} ${WRKSRC}/sh.1 ${WRKSRC}/${PORTNAME}.1
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${CP} ${FILESDIR}/test.c ${WRKSRC}		# sysIII
	@${CP} ${FILESDIR}/pathnames.h ${WRKSRC}	# 43reno
.if ${OSVERSION} < 500005
	@${CP} ${FILESDIR}/ulimit.[ch] ${WRKSRC}	# fbsd52
.endif

post-install:
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/${PORTNAME} /etc/shells.bak; \
	 ${ECHO_CMD} ${PREFIX}/bin/${PORTNAME}) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.post.mk>
