# New ports collection makefile for:	bsd-sort
# Date created:				12 Juni 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sort
PORTVERSION=	20120411
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
		NLSDIR="${PREFIX}/share/nls"

OPTIONS=	NLS		"Compile with NLS support"	on \
		OVERWRITE_BASE	"Replaces base GNU sort"	off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
MAKE_ENV+=	WITHOUT_NLS=yes
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_OVERWRITE_BASE)
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
