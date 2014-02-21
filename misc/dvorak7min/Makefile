# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	dvorak7min
PORTVERSION=	1.6.1
CATEGORIES=	misc
MASTER_SITES=	http://www.linalco.com/ragnar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ncurses-based Dvorak typing tutor

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

.include <bsd.port.pre.mk>

MAKE_ARGS=	PROF="${CPPFLAGS} ${CFLAGS}" LDFLAGS="${LDFLAGS}"

pre-build:
	@cd ${WRKSRC} ; ${MAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorak7min ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
