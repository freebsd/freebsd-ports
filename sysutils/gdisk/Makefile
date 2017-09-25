# Created by: Dmitry N Fomin <fdn@okbire.ru>
# $FreeBSD$

PORTNAME=	gdisk
PORTVERSION=	0.8.10
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF/gptfdisk/gptfdisk/${PORTVERSION}
DISTNAME=	gptfdisk-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	GPT fdisk

LICENSE=	GPLv2

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libpopt.so:devel/popt

WRKSRC=		${WRKDIR}/gptfdisk-${PORTVERSION}

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	CGDISK UTF16
OPTIONS_SUB=	yes
CGDISK_DESC=	Curses-based interactive program
UTF16_DESC=	Support for Unicode partition names
UTF16_CPPFLAGS+=	-DUSE_UTF16
UTF16_LDFLAGS+=	-licuio

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKEFILE=	Makefile.freebsd

PROGRAM_LIST=	fixparts gdisk sgdisk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCGDISK}
PROGRAM_LIST+=	cgdisk
LIB_DEPENDS+=	libncurses.so:devel/ncurses
.endif

.if ${PORT_OPTIONS:MUTF16}
LIB_DEPENDS+=	libicuuc.so:devel/icu
.endif

post-patch:
.if ! ${PORT_OPTIONS:MCGDISK}
	${REINPLACE_CMD} -e '/^all:/s| cgdisk||' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
.for i in ${PROGRAM_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${i}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.endfor

.include <bsd.port.mk>
