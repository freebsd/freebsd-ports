# $FreeBSD$

PORTNAME=	quickjail
PORTVERSION=	0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kevans.dev/kevans/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Utility to quickly create transient single-command jails

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/${PORTNAME}.1.gz \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
