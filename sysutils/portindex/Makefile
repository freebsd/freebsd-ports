# New ports collection makefile for:	portindex
# Date created:		1 Jul 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	portindex
PORTVERSION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://home.tiscali.cz/~cz210552/distfiles/
DISTNAME=	bsdportsutils-${PORTVERSION}

MAINTAINER=	hsn@netmag.cz
COMMENT=	Incremental ports INDEX file builder

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes

PORTDOCS=	*.TXT
PLIST_FILES=	bin/portreadmes bin/portindex
PLIST_DIRS=	share/${PORTNAME}

SOURCES=	bsdpkg freebsdports indexer minorupdates updateall updatereadmes

.for i in ${SOURCES}
PLIST_FILES+=	share/${PORTNAME}/${i}.py
PLIST_FILES+=	share/${PORTNAME}/${i}.pyc
.endfor

do-build:
	${REINPLACE_CMD} -e "s,ports.pck,/var/db/portindex.pck," ${WRKSRC}/freebsdports.py
	${SED} -e "s,%%DATADIR%%,${DATADIR}," ${FILESDIR}/portindex.sh > ${WRKSRC}/portindex
	${SED} -e "s,%%DATADIR%%,${DATADIR}," ${FILESDIR}/portreadmes.sh > ${WRKSRC}/portreadmes

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${DATADIR}
	${PYTHON_CMD} -c "import compileall;compileall.compile_dir('${DATADIR}')"
	${INSTALL_SCRIPT} ${WRKSRC}/portindex ${WRKSRC}/portreadmes ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
