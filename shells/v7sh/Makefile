# Created by: Cyrille.Lefevre@laposte.net
# $FreeBSD$

PORTNAME=	v7sh
PORTVERSION=	1.0
PORTREVISION=	1
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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the UNIX 7th Edition shell

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		uidfix
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	SYSIII RENO ULTRIX
OPTIONS_DEFAULT=	SYSIII RENO ULTRIX
SYSIII_DESC=	System III enhancements
RENO_DESC=	4.3BSD-Reno enhancements
ULTRIX_DESC=	Ultrix 3.1 enhancements
SYSIII_CFLAGS=	-DSYSIII
RENO_CFLAGS=	-DRENO
ULTRIX_CFLAGS=	-DULTRIX

post-extract:
	@${MV} ${WRKSRC}/sh.1 ${WRKSRC}/${PORTNAME}.1
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${CP} ${FILESDIR}/test.c ${WRKSRC}		# sysIII
	@${CP} ${FILESDIR}/pathnames.h ${WRKSRC}	# 43reno

.include <bsd.port.mk>
