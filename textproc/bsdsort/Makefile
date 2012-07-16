# New ports collection makefile for:	bsd-sort
# Date created:				12 June 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sort
PORTVERSION=	20120716
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed version of sort

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${PORTNAME}
MANCOMPRESSED=	yes
MAN1=		sort.1

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man" \
		NLSDIR="${PREFIX}/share/nls" \
		MK_GNU_SORT="no"

CFLAGS+=	-std=c99

OPTIONS_DEFINE=		THREADS NLS OVERWRITE_BASE
OVERWRITE_BASE_DESC=	"Replaces base GNU sort"
OPTIONS_DEFAULT=	THREADS NLS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
MAKE_ENV+=	WITHOUT_NLS=yes
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
MAKE_ENV+=	WITH_THREADS=yes
.endif

.if ${PORT_OPTIONS:MOVERWRITE_BASE}
PREFIX=		/usr
PLIST_SUB+=	OVERWRITE_BASE="" NO_OVERWRITE_BASE="@comment "
.else
PLIST_SUB+=	OVERWRITE_BASE="@comment " NO_OVERWRITE_BASE=""
.endif

.if defined(WITH_OVERWRITE_BASE) && exists(${PREFIX}/bin/sort)
pre-install:
	${INSTALL_PROGRAM} ${PREFIX}/bin/sort ${PREFIX}/bin/gnusort
.endif

post-install:
	${LN} -s ${PREFIX}/bin/sort ${PREFIX}/bin/bsdsort
.if !defined(WITH_OVERWRITE_BASE)
	${LN} -s /usr/bin/sort ${PREFIX}/bin/gnusort
.endif

.include <bsd.port.post.mk>
