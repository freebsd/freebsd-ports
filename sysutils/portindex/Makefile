# New ports collection makefile for:	portindex
# Date created:		1 Jul 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	portindex
PORTVERSION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://people.tecnik93.com/~radim/distfiles/
DISTNAME=	bsdportsutils-${PORTVERSION}

MAINTAINER=	hsn@netmag.cz
COMMENT=	Incremental ports INDEX file builder

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes

PORTDOCS=	*.TXT
PLIST_DIRS=	share/${PORTNAME}

PORTINDEX=	bsdpkg freebsdports indexer updatereadmes
MINORUPDATES=	minorupdates
MISCTOOLS=	updateall
PKGHISTORY=	loadindex query updinst

SOURCES=	${PORTINDEX}
EXECUTABLES=	portindex portreadmes

OPTIONS=	MINOR "Install minorupdates program" off \
		MISCTOOLS "Install misc. tools" off \
		PKGHISTORY "Install pkghistory package" off

.include <bsd.port.pre.mk>

.ifdef WITH_MINOR
RUN_DEPENDS+=	${LOCALBASE}/sbin/portversion:${PORTSDIR}/sysutils/portupgrade
SOURCES+=	${MINORUPDATES}
EXECUTABLES+=	${MINORUPDATES}
.endif

.ifdef WITH_MISCTOOLS
SOURCES+=	${MISCTOOLS}
EXECUTABLES+=	${MISCTOOLS}
.endif

.ifdef WITH_PKGHISTORY
SOURCES+=	${PKGHISTORY}
EXECUTABLES+=	${PKGHISTORY}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pg.py:${PORTSDIR}/databases/py-PyGreSQL
PLIST_FILES+=	share/${PORTNAME}/create.sql
.endif

.for i in ${SOURCES}
PLIST_FILES+=	share/${PORTNAME}/${i}.py
PLIST_FILES+=	share/${PORTNAME}/${i}.pyc
.endfor

.for i in ${EXECUTABLES}
PLIST_FILES+=	bin/${i}
.endfor

do-build:
	${REINPLACE_CMD} -e "s,ports.pck,/var/db/portindex.pck," ${WRKSRC}/freebsdports.py
.for i in ${EXECUTABLES}
	${SED} -e "s,%%DATADIR%%,${DATADIR}," ${FILESDIR}/${i}.sh > ${WRKSRC}/${i}
.endfor

do-install:
	${MKDIR} ${DATADIR}
.for i in ${SOURCES}
	${INSTALL_DATA} ${WRKSRC}/${i}.py ${DATADIR}
.endfor
	${PYTHON_CMD} -c "import compileall;compileall.compile_dir('${DATADIR}')"
.for i in ${EXECUTABLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.ifdef WITH_PKGHISTORY
	${INSTALL_DATA} ${WRKSRC}/create.sql ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.TXT ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
