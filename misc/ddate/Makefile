# New ports collection makefile for:   ddate
# Date created:		26 January 2005
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ddate
PORTVERSION=	2.21
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/v${PORTVERSION}/ \
		CRITICAL
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command to print the date in Discordian date format

LICENSE=	GPLv2

PLIST_FILES=	bin/ddate

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		ddate.1

OPTIONS=	USFORMAT  "Use US time format" off \
		PRAISEBOB "Use SubGenius slogans" off \
		KILLBOB   "Use countdown to X-Day" on

.include <bsd.port.pre.mk>

.if defined(WITH_USFORMAT)
CFLAGS+=	-DUS_FORMAT=\"1\"
.endif

.if defined(WITH_PRAISEBOB)
CFLAGS+=	-DPRAISE_BOB=\"13013\"
.endif

.if defined(WITH_KILLBOB)
CFLAGS+=	-DKILL_BOB=\"13013\"
.endif

do-build:
	${CC} ${WRKSRC}/misc-utils/ddate.c ${CFLAGS} \
		-o ${WRKSRC}/misc-utils/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/misc-utils/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/misc-utils/ddate.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
