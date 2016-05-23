# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sort
PORTVERSION=	20120716
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD-licensed version of sort

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man" \
		NLSDIR="${PREFIX}/share/nls" \
		NO_WERROR="defined" \
		MK_GNU_SORT="no"
USES=		uidfix

CFLAGS+=	-std=c99

PLIST_FILES=	bin/sort \
		bin/bsdsort \
		bin/gnusort \
		man/man1/sort.1.gz

OPTIONS_DEFINE=		THREADS NLS
OPTIONS_DEFAULT=	THREADS
OPTIONS_SUB=		yes

NLS_MAKE_ENV_OFF=	WITHOUT_NLS=yes
NLS_PLIST_FILES=	share/nls/hu_HU.ISO8859-2/sort.cat
THREADS_MAKE_ENV=	WITH_THREADS=yes

post-install:
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s sort bsdsort)
	${LN} -s /usr/bin/sort ${STAGEDIR}${PREFIX}/bin/gnusort

.include <bsd.port.mk>
