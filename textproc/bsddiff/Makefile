PORTNAME=	diff
PORTVERSION=	20120705
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD-licensed version of diff from OpenBSD
WWW=		https://www.freebsd.org/projects/ideas/ #p-bsdtexttools

USES=		uidfix
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/share/man/man" \
		CATDIR="${PREFIX}/share/man/man"

post-install:
	${LN} -sf ${PREFIX}/bin/bsddiff ${STAGEDIR}${PREFIX}/bin/diff

.include <bsd.port.mk>
