# New ports collection makefile for:	mimetex
# Date created:		2006-02-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	mimetex
PORTVERSION=	1.60
PORTREVISION=	1
CATEGORIES=	www math
MASTER_SITES=	http://www.forkosh.com/ \
		http://nivi.interfree.it/distfiles/${DIST_SUBDIR}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	A CGI script that lets you embed LaTeX math in your HTML pages

NO_WRKSUBDIR=	yes
USE_APACHE=	yes
USE_ZIP=	yes

FETCH_CMD=	/usr/bin/fetch -rR	# see PR bin/76134
LN_OPTS=	-sf

CGI_BIN=	${PREFIX}/www/cgi-bin/
CGI_PRG=	${PORTNAME}.cgi
WWW_DIR=	${PREFIX}/www/data/mimetex/

do-build:
	cd ${WRKDIR};\
	${CC} ${CFLAGS} -DAA mimetex.c gifsave.c -lm -o ${CGI_PRG}

do-install:
	${MKDIR} ${CGI_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${CGI_PRG} ${CGI_BIN}/${CGI_PRG}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${DOCSDIR}
	${MKDIR} ${WWW_DIR}
	${LN} ${LN_OPTS} ${DOCSDIR}/${PORTNAME}.html ${WWW_DIR}/index.html
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
