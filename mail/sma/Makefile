# $FreeBSD$

PORTNAME=	sma
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Program that analyses Sendmail log entries

ALL_TARGET=	sma
SAMPLEFILES=	sma.conf
DOCSFILES=	BUGS COPYRIGHT HISTORY README TODO

.include <bsd.port.options.mk>

do-configure:
	${REINPLACE_CMD} -e "s,CC	=,CC?=	," \
		-e "s,CFLAGS	= -Wall -O,CFLAGS+=	," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sma ${STAGEDIR}${PREFIX}/bin/sma
	${INSTALL_MAN} ${WRKSRC}/sma.8 ${STAGEDIR}${MANPREFIX}/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${SAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
