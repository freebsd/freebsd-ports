# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	httping
PORTVERSION=	2.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ping-like tool for HTTP requests

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		httping.1
PLIST_FILES=	bin/httping

OPTIONS_DEFINE=	NCURSES

NCURSES_DESC=	ncurses support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNCURSES}
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
MAKE_ENV+=	SSL=yes NC=yes FW=yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
