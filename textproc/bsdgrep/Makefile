# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grep
PORTVERSION=	20111002
PORTREVISION=	1
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

OPTIONS_DEFINE=	GNU_COMPAT NLS
OPTIONS_DEFAULT=	GNU_COMPAT
GNU_COMPAT_DESC=	Use GNU regex library (recommended)

CONFLICTS=	gnugrep-*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
MAKE_ENV+=	WITHOUT_NLS=yes
PLIST_SUB+=	NLS="@comment "
.endif

.if !${PORT_OPTIONS:MGNU_COMPAT}
MAKE_ENV+=	WITHOUT_GNU_COMPAT=yes
.endif

pre-install:
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${PREFIX}/share/nls/gl_ES.ISO8859-1
.endif

post-install:
	${LN} -s ${PREFIX}/bin/grep ${PREFIX}/bin/bsdgrep
	${LN} -s /usr/bin/grep ${PREFIX}/bin/gnugrep

.include <bsd.port.post.mk>
