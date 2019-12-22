# $FreeBSD$

PORTNAME=	portal
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	ports-mgmt

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Front-end to pkg(8)

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	culot

USES=		ncurses compiler:c++11-lib

.include <bsd.port.pre.mk>

.if ${NCURSESLIB} != /usr/lib
CFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-L${NCURSESLIB}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
