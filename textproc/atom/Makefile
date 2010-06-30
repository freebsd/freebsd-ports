# New ports collection Makefile for:	atom
# Date created:	 	3 June 2009
# Whom:			utisoft@gmail.com
#
# $FreeBSD$
#

PORTNAME=	atom
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.bayofrum.net/dist/atom/ \
		http://muuz.deadbbs.com/FreeBSD/atom/

MAINTAINER=	utisoft@gmail.com
COMMENT=	Converts text files to html with special attributes

MAN1=	atom.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/atom
PORTDOCS=	COPYING \
		README \
		TODO \
		testFile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for DOC in ${PORTDOCS}
		${CP} -R ${WRKSRC}/${DOC} ${DOCSDIR}/
.	endfor
.endif

.include <bsd.port.mk>
