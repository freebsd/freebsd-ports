# $FreeBSD$

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

#OPTIONS=	USFORMAT  "Use US time format" off \
#		PRAISEBOB "Use SubGenius slogans" off \
#		KILLBOB   "Use countdown to X-Day" on

OPTIONS_DEFINE=	USFORMAT PRAISEBOB KILLBOB

USFORMAT_DESC=	US time format
PRAISEBOB_DESC=	SubGenius slogans
KILLBOB_DESC=	Countdown to X-Day

OPTIONS_DEFAULT=KILLBOB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSFORMAT}
CFLAGS+=	-DUS_FORMAT=\"1\"
.endif

.if ${PORT_OPTIONS:MPRAISEBOB}
CFLAGS+=	-DPRAISE_BOB=\"13013\"
.endif

.if ${PORT_OPTIONS:MKILLBOB}
CFLAGS+=	-DKILL_BOB=\"13013\"
.endif

do-build:
	${CC} ${WRKSRC}/misc-utils/ddate.c ${CFLAGS} \
		-o ${WRKSRC}/misc-utils/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/misc-utils/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/misc-utils/ddate.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
