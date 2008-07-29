# New ports collection makefile for:	bsd-grep
# Date created:				12 Juni 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grep
PORTVERSION=	20080725
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed version of grep from OpenBSD

WRKSRC=		${WRKDIR}/${PORTNAME}
MANCOMPRESSED=	yes
MAN1=		grep.1
MLINKS=		grep.1 egrep.1 \
		grep.1 fgrep.1 \
		grep.1 zgrep.1 \
		grep.1 zegrep.1 \
		grep.1 zfgrep.1

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man" \
		NLSDIR="${PREFIX}/share/nls"

OPTIONS=	NLS	"Compile with NLS support"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
MAKE_ENV+=	WITHOUT_NLS=yes
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@cd ${WRKSRC}; ${MAKE} clean

post-install:
	${LN} -s ${PREFIX}/bin/grep ${PREFIX}/bin/bsdgrep
	${LN} -s /usr/bin/grep ${PREFIX}/bin/gnugrep

.include <bsd.port.post.mk>
