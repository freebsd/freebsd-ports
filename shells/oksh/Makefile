# $FreeBSD$

PORTNAME=	oksh
DISTVERSION=	20180401
CATEGORIES=	shells
MASTER_SITES=	https://devio.us/~bcallah/oksh/

MAINTAINER=	bcallah@openbsd.org
COMMENT=	Portable OpenBSD Korn shell

LICENSE=	PD

HAS_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
