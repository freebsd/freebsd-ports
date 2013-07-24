# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	httping
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ping-like tool for HTTP requests

USES=		gmake

MAN1=		httping.1
PLIST_FILES=	bin/httping

OPTIONS_DEFINE=	NCURSES FFTW SSL

OPTIONS_DEFAULT=NCURSES SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNCURSES}
MAKE_ENV+=	NC=yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
MAKE_ENV+=	NC=no
.endif

.if ${PORT_OPTIONS:MFFTW}
MAKE_ENV+=	FW=yes
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
.else
MAKE_ENV+=	FW=no
.endif

.if ${PORT_OPTIONS:MSSL}
MAKE_ENV+=	SSL=yes
.else
MAKE_ENV+=	SSL=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
