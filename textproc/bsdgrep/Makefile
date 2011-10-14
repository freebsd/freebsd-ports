# New ports collection makefile for:	bsd-grep
# Date created:				12 Juni 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grep
PORTVERSION=	20111002
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed version of grep

MANCOMPRESSED=	maybe
MAN1=		grep.1
MLINKS=		grep.1 bzegrep.1 \
		grep.1 bzfgrep.1 \
		grep.1 bzgrep.1 \
		grep.1 egrep.1 \
		grep.1 fgrep.1 \
		grep.1 lzegrep.1 \
		grep.1 lzfgrep.1 \
		grep.1 lzgrep.1 \
		grep.1 xzegrep.1 \
		grep.1 xzfgrep.1 \
		grep.1 xzgrep.1 \
		grep.1 zgrep.1 \
		grep.1 zegrep.1 \
		grep.1 zfgrep.1

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man" \
		NLSDIR="${PREFIX}/share/nls"

OPTIONS=	NLS		"Compile with NLS support"		on \
		GNU_COMPAT	"Use GNU regex library (recommended)"	on

CONFLICTS=	gnugrep-*

.include <bsd.port.pre.mk>

.if !(${OSVERSION} >= 900012 || (${OSVERSION} < 900000 && ${OSVERSION} >= 800505))
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/bin
.endif

.if defined(WITHOUT_NLS)
MAKE_ENV+=	WITHOUT_NLS=yes
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_GNU_COMPAT)
MAKE_ENV+=	WITHOUT_GNU_COMPAT=yes
.endif

pre-install:
.if defined(WITH_NLS)
	${MKDIR} ${LOCALBASE}/share/nls/gl_ES.ISO8859-1
.endif

post-install:
	${LN} -s ${PREFIX}/bin/grep ${PREFIX}/bin/bsdgrep
	${LN} -s /usr/bin/grep ${PREFIX}/bin/gnugrep

.include <bsd.port.post.mk>
