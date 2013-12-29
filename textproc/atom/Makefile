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

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/atom man/man1/atom.1.gz
PORTDOCS=	README TODO testFile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
