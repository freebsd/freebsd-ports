# ex:ts=8
# Ports collection makefile for:	dvorakNG
# Date created:			Mar 26, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dvorakng
PORTVERSION=	0.5.0
CATEGORIES=	misc
MASTER_SITES=	http://www.free.of.pl/n/nopik/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Dvorak typing tutor

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
MAKE_ARGS=	PROF="-I${LOCALBASE}/include ${CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lncurses -lgnugetopt"
.else
MAKE_ARGS=	PROF="${CFLAGS}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorakng ${PREFIX}/bin

.include <bsd.port.post.mk>
