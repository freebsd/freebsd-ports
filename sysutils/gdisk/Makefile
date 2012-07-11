# New ports collection makefile for:	gdisk
# Date created:		12 July 2010
# Whom:			Dmitry N Fomin <fdn@okbire.ru>
#
# $FreeBSD$
#

PORTNAME=	gdisk
PORTVERSION=	0.8.5
CATEGORIES=	sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gptfdisk/gptfdisk/${PORTVERSION}
DISTNAME=	gptfdisk-${PORTVERSION}

MAINTAINER=	fdn@okbire.ru
COMMENT=	GPT fdisk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		popt.0:${PORTSDIR}/devel/popt

WRKSRC=		${WRKDIR}/gptfdisk-${PORTVERSION}

FETCH_ARGS=	-Rr

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	CGDISK UTF16
CGDISK_DESC=	A curses-based interactive program
UTF16_DESC=	Support for Unicode partition names

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 701100
IGNORE=		is unsupported on FreeBSD 7.1-RELEASE or earlier
.endif

MAKEFILE=	Makefile.freebsd

PROGRAM_LIST=	fixparts gdisk sgdisk
PLIST_FILES=	${PROGRAM_LIST:C,^,sbin/,}

.if ${PORT_OPTIONS:MCGDISK}
PROGRAM_LIST+=	cgdisk
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.if ${PORT_OPTIONS:MUTF16}
LIB_DEPENDS+=	icuuc.48:${PORTSDIR}/devel/icu
.endif

MAN8=
.for i in ${PROGRAM_LIST}
MAN8+=	${i}.8
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|/usr/include/||' ${WRKSRC}/guid.h
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${MAKEFILE}

.if empty(PORT_OPTIONS:MCGDISK)
	${REINPLACE_CMD} -e '/^all:/s| cgdisk||' ${WRKSRC}/${MAKEFILE}
.endif

.if empty(PORT_OPTIONS:MUTF16)
	${REINPLACE_CMD} -e 's| -D USE_UTF16||' \
			 -e 's| -licuio||' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
.for i in ${PROGRAM_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${i}.8 ${MAN8PREFIX}/man/man8
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
