# $FreeBSD$

PORTNAME=	portal
PORTVERSION=	0.3
CATEGORIES=	ports-mgmt

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Front-end to pkg(8)

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	Does not build

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	culot

USES=		compiler:c++11-lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
