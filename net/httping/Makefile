# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	httping
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.vanheusden.com/httping/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ping-like tool for HTTP requests

LICENSE=	GPLv2

USES=		gmake gettext tar:tgz

PLIST_FILES=	bin/httping man/man1/httping.1.gz

OPTIONS_DEFINE=	NCURSES FFTW SSL

OPTIONS_DEFAULT=NCURSES SSL
NCURSES_USES=	ncurses

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
LIB_DEPENDS+=	libfftw3.so:math/fftw3
.else
MAKE_ENV+=	FW=no
.endif

.if ${PORT_OPTIONS:MSSL}
MAKE_ENV+=	SSL=yes
USES+=		ssl
.else
MAKE_ENV+=	SSL=no
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200000
MAKE_ENV+=	TFO=yes
.endif

post-patch-NCURSES-on:
	@${REINPLACE_CMD} "s/lncursesw/l${NCURSES_IMPL}/g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
