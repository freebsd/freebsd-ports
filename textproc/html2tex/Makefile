# New ports collection makefile for:    html2tex
# Date created:                 Nov 5 2008
# Whom:                         martin.dieringer@gmx.de
#
# $FreeBSD$
#

PORTNAME=	html2tex
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.iwriteiam.nl/
DISTNAME=	html2tex_c.txt
EXTRACT_SUFX=	# empty

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	HTML to LaTeX converter, last modified 2010

PLIST_FILES=	bin/html2tex
NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/html2tex.c

do-build:
	cd ${WRKSRC} &&	${CC} -o html2tex html2tex.c

do-install:
	cd ${WRKSRC} && ${CP} html2tex ${PREFIX}/bin

.include <bsd.port.mk>
