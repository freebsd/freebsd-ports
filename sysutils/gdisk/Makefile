# Created by: Dmitry N Fomin <fdn@okbire.ru>
# $FreeBSD$

PORTNAME=	gdisk
PORTVERSION=	0.8.6
CATEGORIES=	sysutils
MASTER_SITES=	SF/gptfdisk/gptfdisk/${PORTVERSION}
DISTNAME=	gptfdisk-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	GPT fdisk

LICENSE=	GPLv2

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libpopt.so:${PORTSDIR}/devel/popt

WRKSRC=		${WRKDIR}/gptfdisk-${PORTVERSION}

FETCH_ARGS=	-Rr

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	CGDISK UTF16
CGDISK_DESC=	A curses-based interactive program
UTF16_DESC=	Support for Unicode partition names

MAKEFILE=	Makefile.freebsd

PROGRAM_LIST=	fixparts gdisk sgdisk
PLIST_FILES=	${PROGRAM_LIST:C,^,sbin/,}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCGDISK}
PROGRAM_LIST+=	cgdisk
LIB_DEPENDS+=	libncurses.so:${PORTSDIR}/devel/ncurses
.endif

.if ${PORT_OPTIONS:MUTF16}
LIB_DEPENDS+=	libicuuc.so:${PORTSDIR}/devel/icu
.endif

MAN8=
.for i in ${PROGRAM_LIST}
MAN8+=	${i}.8
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|/usr/include/||' ${WRKSRC}/guid.h
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${MAKEFILE}

.if ! ${PORT_OPTIONS:MCGDISK}
	${REINPLACE_CMD} -e '/^all:/s| cgdisk||' ${WRKSRC}/${MAKEFILE}
.endif

.if ! ${PORT_OPTIONS:MUTF16}
	${REINPLACE_CMD} -e 's| -D USE_UTF16||' \
			 -e 's| -licuio||' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
.for i in ${PROGRAM_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${i}.8 ${MAN8PREFIX}/man/man8
.endfor

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
