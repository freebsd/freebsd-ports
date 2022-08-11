PORTNAME=	mimetex
PORTVERSION=	20120331.1.74
CATEGORIES=	www math
MASTER_SITES=	LOCAL/nivit/${PORTNAME}/${PORTVERSION}/ \
		http://www.forkosh.com/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	CGI script that lets you embed LaTeX math in your HTML pages

LICENSE=	GPLv3

NO_WRKSUBDIR=	yes
USES=		zip

OPTIONS_DEFINE=	ANTIALIASING DOCS STATIC
OPTIONS_DEFAULT=	ANTIALIASING
ANTIALIASING_DESC=	Use image format with anti-aliasing
STATIC_DESC=	Possible use of mimetex on another machine

PORTDOCS=	${PORTNAME}.html

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
	cd ${WRKSRC};\
	${CC} ${CFLAGS} ${STATIC_MIMETEX} ${IMAGES_TYPE} ${USER_OPTIONS} mimetex.c gifsave.c -lm -o mimetex.cgi

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/mimetex.cgi ${STAGEDIR}${WWWDIR}/cgi-bin/mimetex.cgi
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
