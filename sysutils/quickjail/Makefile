# $FreeBSD$

PORTNAME=	quickjail
PORTVERSION=	0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kevans.dev/kevans/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Utility to quickly create transient single-command jails

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 uidfix

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/share/man/man"

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
