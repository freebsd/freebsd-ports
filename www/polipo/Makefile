# Created by: Frank Behrens <frank@pinky.sax.de>
# $FreeBSD$

PORTNAME=	polipo
PORTVERSION=	1.1.1
CATEGORIES=	www
MASTER_SITES=	http://www.pps.univ-paris-diderot.fr/~jch/software/files/polipo/

MAINTAINER=	frank@pinky.sax.de
COMMENT=	Small and fast caching web proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo
USE_RC_SUBR=	polipo

INFO=		polipo

.include <bsd.port.pre.mk>

DOCSDIR=	${DATADIR}/www/doc
PORTDOCS=	*

SUB_FILES=	pkg-message pkg-install pkg-deinstall 400.polipo
SUB_LIST+=	USER=${PUSER} GROUP=${PGRP} DESTDIR=${DESTDIR} PCONFIGDIR=${PCONFIGDIR} \
		PCACHEDIR=${PCACHEDIR} PPIDDIR=${PPIDDIR} PPIDFILE=${PPIDFILE} \
		PLOGFILE=${PLOGFILE}
PLIST_SUB=	PCACHEDIR=${PCACHEDIR}

# polipo installation options, propagated to install scripts
PUSER?=		polipo
PGRP?=		polipo
PCONFIGDIR?=	${PREFIX}/etc/polipo/
PCACHEDIR?=	/var/cache/polipo
PPIDDIR?=	/var/run/polipo/
PPIDFILE=	${PPIDDIR}polipo.pid
PLOGFILE?=	/var/log/polipo
MAKE_ENV+=	DISK_CACHE_ROOT=${PCACHEDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily/ \
		${STAGEDIR}${PCONFIGDIR} \
		${STAGEDIR}${PCACHEDIR} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/polipo ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/400.polipo ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_MAN} ${WRKSRC}/polipo.man ${STAGEDIR}${PREFIX}/man/man1/polipo.1
	${INSTALL_DATA} ${WRKSRC}/config.sample ${WRKSRC}/forbidden.sample ${STAGEDIR}${PCONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/polipo.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/html/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/localindex.html ${STAGEDIR}${DATADIR}/www/index.html

.include <bsd.port.post.mk>
