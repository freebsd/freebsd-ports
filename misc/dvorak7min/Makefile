# New ports collection makefile for:	dvorak7min
# Date created:			31 Jan 2003
# Whom:				Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	dvorak7min
PORTVERSION=	1.6.1
CATEGORIES=	misc
MASTER_SITES=	http://www.linalco.com/ragnar/

MAINTAINER=	llwang@infor.org
COMMENT=	An ncurses-based Dvorak typing tutor

USE_GETOPT_LONG=yes

.include <bsd.port.pre.mk>

MAKE_ARGS=	PROF="${CPPFLAGS} ${CFLAGS}" LDFLAGS="${LDFLAGS}"

pre-build:
	@cd ${WRKSRC} ; ${MAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorak7min ${PREFIX}/bin

.include <bsd.port.post.mk>
