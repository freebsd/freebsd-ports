# New ports collection makefile for:	portindex
# Date created:		1 Jul 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	portindex
PORTVERSION=	18
PORTREVISION=	1
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
PLIST_FILES=	etc/portindex.conf.sample
PORTINDEX=	bsdpkg freebsdports indexer updatereadmes config \
		portindexdb
MINORUPDATES=	minorupdates stealthupdates pointupdates
MISCTOOLS=	updateall
PKGHISTORY=	loadindex query updinst

SOURCES=	${PORTINDEX}
EXECUTABLES=	portindex portreadmes portindexdb

OPTIONS=	PKGHISTORY "Install pkghistory package" off \
		MINORUPDATES "Install point/minor/stealth updates scripts" off \
		MISCTOOLS "Install updateall script" off

.include <bsd.port.pre.mk>

.ifdef WITH_MINORUPDATES
SOURCES+=	${MINORUPDATES}
EXECUTABLES+=	${MINORUPDATES}
.endif

.ifdef WITH_MISCTOOLS
.ifndef WITH_PKGHISTORY
BROKEN=		Option updateall requires pkghistory option
.else
SOURCES+=	${MISCTOOLS}
EXECUTABLES+=	${MISCTOOLS}
.endif
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
	${REINPLACE_CMD} -e "s,portindex.conf,${PREFIX}/etc/portindex.conf," ${WRKSRC}/config.py
.for i in ${EXECUTABLES}
	${SED} -e "s,%%DATADIR%%,${DATADIR}," ${FILESDIR}/${i}.sh > ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/portindex.conf ${PREFIX}/etc/portindex.conf.sample
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
