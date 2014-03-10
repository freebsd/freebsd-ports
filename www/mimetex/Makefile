# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	mimetex
PORTVERSION=	20120331.1.74
PORTREVISION=	0
CATEGORIES=	www math
MASTER_SITES=	LOCAL/nivit/${PORTNAME}/${PORTVERSION}/ \
		http://www.forkosh.com/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A CGI script that lets you embed LaTeX math in your HTML pages

LICENSE=	GPLv3

NO_WRKSUBDIR=	yes
USES=		zip

OPTIONS_DEFINE=	ANTIALIASING DOCS STATIC
OPTIONS_DEFAULT=	ANTIALIASING
DESC_ANTIALIASING=	Use image format with anti-aliasing
DESC_STATIC=	Possible use of mimetex on another machine

PORTDOCS=	${PORTNAME}.html

NO_STAGE=	yes
.include <bsd.port.options.mk>
# usefull if you run mimetex on another machine
.if ${PORT_OPTIONS:MSTATIC}
STATIC_MIMETEX=	-static
.endif
# anti-aliasing no/yes
.if ${PORT_OPTIONS:MANTIALIASING}
IMAGES_TYPE=	-DAA
.else
IMAGES_TYPE=	-DGIF
.endif
# other options (see mimetex.c or online documentation)
# example: make install USER_OPTIONS='-DCACHEPATH=\"/tmp\" -DDISPLAYSIZE=10'
USER_OPTIONS?=

do-build:
	cd ${WRKDIR};\
	${CC} ${CFLAGS} ${STATIC_MIMETEX} ${IMAGES_TYPE} ${USER_OPTIONS} mimetex.c gifsave.c -lm -o mimetex.cgi
do-install:
	${MKDIR} ${WWWDIR}/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/mimetex.cgi ${WWWDIR}/cgi-bin/mimetex.cgi
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
