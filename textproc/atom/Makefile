# $FreeBSD$

PORTNAME=	atom
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.bayofrum.net/dist/atom/ \
		http://muuz.deadbbs.com/FreeBSD/atom/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Converts text files to html with special attributes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAN1=	atom.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/atom
PORTDOCS=	README \
		TODO \
		testFile

NO_STAGE=	yes
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
