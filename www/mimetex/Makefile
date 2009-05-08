# New ports collection makefile for:	mimetex
# Date created:		2006-02-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	mimetex
PORTVERSION=	20080906.1.70
PORTREVISION=	1
CATEGORIES=	www math
MASTER_SITES=	http://nivi.interfree.it/distfiles/${DIST_SUBDIR}/ \
		http://www.forkosh.com/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A CGI script that lets you embed LaTeX math in your HTML pages

NO_WRKSUBDIR=	yes
USE_APACHE=	1.3+
USE_ZIP=	yes

FETCH_CMD=	/usr/bin/fetch -rR	# see PR bin/76134
LN_OPTS=	-sf

CGI_BIN=	${PREFIX}/www/cgi-bin/
CGI_PRG=	${PORTNAME}.cgi
WWW_DIR=	${PREFIX}/www/data/mimetex/

# usefull if you run mimetex on another machine
.if defined(WITH_STATIC)
STATIC_MIMETEX=	-static
.endif
# anti-aliasing no/yes
.if defined(WITHOUT_ANTIALIASING)
IMAGES_TYPE=	-DGIF
.else
IMAGES_TYPE=	-DAA
.endif
# other options (see mimetex.c or online documentation)
# example: make install USER_OPTIONS='-DCACHEPATH=\"/tmp\" -DDISPLAYSIZE=10'
USER_OPTIONS?=

do-build:
	cd ${WRKDIR};\
	${CC} ${CFLAGS} ${STATIC_MIMETEX} ${IMAGES_TYPE} ${USER_OPTIONS} mimetex.c gifsave.c -lm -o ${CGI_PRG}

do-install:
	${MKDIR} ${CGI_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${CGI_PRG} ${CGI_BIN}/${CGI_PRG}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${DOCSDIR}
	${MKDIR} ${WWW_DIR}
	${LN} ${LN_OPTS} ${DOCSDIR}/${PORTNAME}.html ${WWW_DIR}/index.html

post-install:
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
