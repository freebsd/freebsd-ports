PORTNAME=	diff
PORTVERSION=	20120705
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD-licensed version of diff from OpenBSD

USES=		uidfix
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man"

post-install:
	${LN} -sf ${PREFIX}/bin/bsddiff ${STAGEDIR}${PREFIX}/bin/diff

.include <bsd.port.mk>
