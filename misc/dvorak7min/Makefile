# New ports collection makefile for:	dvorak7min
# Date created:			31 Jan 2003
# Whom:				Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	dvorak7min
PORTVERSION=	1.6
CATEGORIES=	misc
MASTER_SITES=	http://lightside.eresmas.com/

MAINTAINER=	llwang@infor.org
COMMENT=	An ncurses-based Dvorak typing tutor

MAKE_ARGS=	PROF="${CFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lncurses -lgnugetopt"
.endif

pre-build:
	@cd ${WRKSRC} ; ${MAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorak7min ${PREFIX}/bin

.include <bsd.port.post.mk>
