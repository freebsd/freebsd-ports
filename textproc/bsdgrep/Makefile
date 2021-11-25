# Created by: Gabor Kovesdan <gabor@FreeBSD.org>

PORTNAME=	grep
DISTVERSION=	2.6.0
DISTVERSIONSUFFIX=	-FreeBSD
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/kevans
PKGNAMEPREFIX=	bsd-

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	BSD-licensed version of grep

LICENSE=	BSD2CLAUSE

# This port should be deprecated once stable/12 goes EoL.  bsdgrep shipped by
# default in FreeBSD 13.0.
IGNORE_FreeBSD_13=	only for FreeBSD 12.x
IGNORE_FreeBSD_14=	only for FreeBSD 12.x

USES=	uidfix

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man" \
		NLSDIR="${PREFIX}/share/nls" \
		WITHOUT_TESTS=yes
CFLAGS+=	-std=gnu99

OPTIONS_DEFINE=	GNU_COMPAT NLS
OPTIONS_DEFAULT=	GNU_COMPAT
OPTIONS_SUB=		yes
GNU_COMPAT_DESC=	Use GNU regex library (recommended)

CONFLICTS=	gnugrep

NLS_MAKE_ENV=	MK_NLS=yes
NLS_MAKE_ENV_OFF=	MK_NLS=no
GNU_COMPAT_MAKE_ENV=	MK_GNU_GREP_COMPAT=yes
GNU_COMPAT_MAKE_ENV_OFF=MK_GNU_GREP_COMPAT=no

pre-install-NLS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/nls/gl_ES.ISO8859-1

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/bin/grep ${STAGEDIR}${PREFIX}/bin/bsdgrep

.include <bsd.port.mk>
