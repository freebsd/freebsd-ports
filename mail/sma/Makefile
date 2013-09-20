# $FreeBSD$

PORTNAME=	sma
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Program that analyses Sendmail log entries

MAN8=		sma.8
DOCSFILES=	BUGS COPYRIGHT HISTORY README TODO
SAMPLEFILES=	sma.conf
ALL_TARGET=	sma

NO_STAGE=	yes
do-configure:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.sed
	${SED} -e "s,CC	=,CC?=	," \
		-e "s,CFLAGS	= -Wall -O,CFLAGS+=	," \
		${WRKSRC}/Makefile.sed > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sma ${PREFIX}/bin/sma
	${INSTALL_MAN} ${WRKSRC}/sma.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in ${SAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
