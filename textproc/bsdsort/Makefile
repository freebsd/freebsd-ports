# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sort
PORTVERSION=	20120716
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD-licensed version of sort

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man" \
		NLSDIR="${PREFIX}/share/nls" \
		MK_GNU_SORT="no"
USES=		uidfix

CFLAGS+=	-std=c99

OPTIONS_DEFINE=		THREADS NLS OVERWRITE_BASE
OVERWRITE_BASE_DESC=	Replace base GNU sort
OPTIONS_DEFAULT=	THREADS NLS
OPTIONS_SUB=		yes

NLS_MAKE_ENV_OFF=	WITHOUT_NLS=yes
THREADS_MAKE_ENV=	WITH_THREADS=yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOVERWRITE_BASE}
PREFIX=		/usr
.endif

post-install:
	${LN} -s ${PREFIX}/bin/sort ${STAGEDIR}${PREFIX}/bin/bsdsort
.if empty(OVERWRITE_BASE)
	${LN} -s /usr/bin/sort ${STAGEDIR}${PREFIX}/bin/gnusort
.endif

.include <bsd.port.post.mk>
