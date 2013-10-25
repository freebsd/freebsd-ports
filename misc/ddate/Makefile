# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	ddate
PORTVERSION=	2.22.2
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/v${PORTVERSION:C/^([0-9]*\.[0-9]*).*/\1/}/ \
		CRITICAL
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command to print the date in Discordian date format

LICENSE=	GPLv2

PLIST_FILES=	bin/ddate man/man1/ddate.1.gz

GNU_CONFIGURE=	yes
USE_XZ=		yes

CONFIGURE_ARGS=	--disable-libuuid --disable-libblkid --disable-libmount \
		--disable-mount --disable-losetup --disable-fsck \
		--disable-partx --disable-uuidd --disable-mountpoint \
		--disable-fallocate --disable-unshare --disable-eject \
		--disable-agetty --disable-cramfs --disable-switch_root \
		--disable-pivot_root --disable-kill --disable-utmpdump \
		--disable-rename --disable-login --disable-sulogin \
		--disable-su --disable-schedutils --disable-wall

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
	${INSTALL_PROGRAM} ${WRKSRC}/misc-utils/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/misc-utils/ddate.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
